/*
//=============================================================================================
//									DESCRIPTION

//=============================================================================================
File Name: TheMain_adv2.c

Project Name: Lights2

Target Device/Platform: Basys3 Board (with Microblaze processor on the Artix-7 FPGA)

Tool Version: Xilinx SDK 2015.2

Name: Galit Ilie s1628465

Company: University of Edinburgh

Creation Date and Time: 11/11/2018; 12:30

Description: - The aim of the project is to design a working traffic light for an intersection
			 - There are two traffic lights and one pedestrian light
			 - The hwTimerISR() (which is defined in the xinterruptES3.c file) method is used to do the logic behind the state machines
			 	 * It determines what state you are in and determines the next one
			 	 * It determines what mode you are in and when you change from one mode to another
			 - display_night_mode() method used to trigger the FSM responsible for the night mode
			 - display_emer_mode() method used to trigger the FSM responsible for the emergency  mode
			 - setState() method is responsible for the FSM that determines what do display in the normal operation of the cars and pedestrian traffic lights
*/
//----------------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include "platform.h"
#include "gpio_init.h"
#include "xil_types.h"
#include <stdlib.h>
#include "seg7_display.h"

#include "variables.h"
#include "pedestrain_methods.h"
#include "display_timer.h"
#include "displaying_night_mode.h"
#include "main_traffic_lights.h"
#include "emergency_module.h"

//=============================================================================================
//									Variables
//=============================================================================================

// variables used for logical usage
u16 interrupt_counter 	= 0;						// timer used to operate the car traffic lights and pedestrian lights in the interrupt
u16 display_number 		= 0; 						// number displayed on the 7_seg_display
u32 switches_val    	= 0;						// value of the switches

// trigger variables that trigger states and modes
u8 state_pedestrian 	= FALSE;					// variable used to designate weather a pedestrian is trying to cross or not
u8 trig_emergency 	    = FALSE;					// trigger for emergency
u8 trig_night       	= FALSE;    				// trigger for night mode
u8 trig_normal      	= TRUE;						// trigger for normal mode
u8 display_seg 			= FALSE;					// variable used to decide weather the 5s timer should be displayed

// states & modes
u16 emer_state	    	= 0;						// variables used for emergency FSM
u16 night_state	    	= 0;						// variables used for night-mode FSM
u16 current_state   	= 0;						// variables for car traffic lights FSM
u16 ped_state       	= 0;          				// variables for pedestrian FSM

// timers & counters
u16 display_timer_5s    = display_timer_5s_setter;	// variable timer used to display on the 7_segments
u16 flash_count			 = 0;						// variable for counting how many times to flash
u16 gen_timer		    = car_timer;				// general variable used to set interrupt timer limit
u16 emer_timer_var      = 100;						// variable timer for emergency state controlled by the right button
u16 btn_r_timer_var     = 0;						// timer to detect right button being pressed
//void print(char *str);							// can be used for debugging purposes

//=============================================================================================
//									MAIN
//=============================================================================================

int main()
{
    init_platform();

    int status;

    // Initialise the GPIOs
    status = initGpio();
	if (status != XST_SUCCESS) {
		print("GPIOs initialisation failed!\n\r");
		cleanup_platform();
		return 0;
	}
	// Initialise Interrupt System
	status = setUpInterruptSystem();
	if (status != XST_SUCCESS) {
		print("Interrupt system setup failed!\n\r");
		cleanup_platform();
		return 0;
	}

	while(1) {  							// infinite while loop
		displayNumber(display_number);		// number that is always displayed on the board
	}

    cleanup_platform();
    return 0;
}

//=============================================================================================
//									Interrupt
//=============================================================================================

/**
 * System Interrupt
 * Responsible for the the logic behind the FSMs and function calls
 */
void hwTimerISR(void *CallbackRef)	{
	interrupt_counter++;
	btn_r_timer_var++;
	// Check pedestrian button was pushed
	u8 ped_button = XGpio_DiscreteRead(&P_BTN_LEFT, 1);
	if(ped_button == 1) { 											// make sure you remember the button was pushed
		state_pedestrian = TRUE;
	}

	switches_val = XGpio_DiscreteRead(&SLIDE_SWITCHES,1); 			// Read value from the switches to determine what mode you are in

	/**
	 * Check if the timer speed was incremented for the emergency state
	 */
	if(XGpio_DiscreteRead(&P_BTN_RIGHT,1) && btn_r_timer_var >= 500) {
		emer_timer_var = emer_timer_var + 50;
		btn_r_timer_var = 0;
		if(emer_timer_var == 250) {									// max limit between flashes is 1s
			emer_timer_var=0;
		}
	}


	/**
	 *Check the value of the switches to determine what mode you are in
	 *switches_val == 1 => emergency mode
	 *switches_val == 2 => night mode
	 *switches_val == 3 => normal operational mode
	 */
	if(switches_val == 1) { 	// emergency mode
		trig_emergency = TRUE;
		trig_night     = FALSE;
		trig_normal    = FALSE;
	}
	else if(switches_val == 2) {// night mode
		trig_emergency = FALSE;
		trig_night     = TRUE;
		trig_normal    = FALSE;
	}
	else {						// operate as usual
		trig_normal = TRUE;
		trig_emergency = FALSE;
		trig_night     = FALSE;
	}

	// Display timer for pedestrians
	displayDigit();

	if(interrupt_counter == gen_timer){
		interrupt_counter = 0;
		/**
		 * State Machine instructions for pedestrian crossing street
		 * check if left button was pushed, signalling intention to cross
		 * check if both traffic lights for the cars are red before crossing
		 */
		if(trig_normal == TRUE && state_pedestrian == TRUE && (current_state == 0 || current_state == 5)) {
			if(ped_state == 0) {				// Red light
				movePedestrian(ped_state);
				gen_timer = car_timer;
				ped_state = ped_state + 1;
			}else if(ped_state == 1) {			// Green light for 3 seconds with no blinking
				display_seg = TRUE;				// Start showing the digit on the 7_seg_display
				movePedestrian(ped_state);
				gen_timer = ped_timer_3s;		// make sure timer is set to 3s
				ped_state = ped_state + 1;
			} else if(ped_state == 2){			// Blinking green light for the last 2 seconds
				gen_timer = ped_timer_blink;
				if(flash_count == 5) {			// check if it blinked 5 times
					flash_count = 0;
					ped_state = 0;
					movePedestrian(ped_state);
					state_pedestrian = FALSE;	// Pedestrian done moving once it blinked for 5 times
					if(current_state==5){		// Start counting time for the cars
						gen_timer = car_timer;
					}
				} else {						// Keep Blinking until you blink for 5 times
					movePedestrian(ped_state);
					flash_count = flash_count + 1;
					ped_state = ped_state + 1;
				}
			} else if(ped_state == 3) {			// Oscillate between Green -> ON/OFF (the blinking itself)
				movePedestrian(ped_state);
				ped_state = ped_state - 1;
			}
		}
		else if(trig_normal == TRUE){			// Operate normally until pedestrian button is pressed
			gen_timer = car_timer;
			setState(current_state);
			if(current_state == 7) {			// Restart the cycle once final state is reached
				current_state = 0;
			} else {							// Move to next state unbtill last state is reached
				current_state = current_state + 1;
			}
		}
	}
	/**
	 * Loop responsible for displaying a number to the 7_segment display
	 * Executed every time an interrupt occurs
	 * If pedestrian crosses -> display the time left
	 * else -> display zero
	 */
	if(display_seg == TRUE) {					// Check if green light for pedestrian is set on
		display_timer_5s--;
		display_number = displayTime(display_timer_5s);
		if(display_number == 0){
			display_seg = FALSE;				// Once you display 0 on 7_seg_dispaly
			display_timer_5s = 1250;
		}
	} else {
		display_number = 0;						// if the pedestrian is not crossing then display 0 on the 7_seg_displays
	}

	/**
	 * FSM responsible for the emergency mode
	 * Is executed only if the value of the slide-switches is equal to 1
	 */
	if(trig_emergency == TRUE && interrupt_counter >= emer_timer_var) {	// Check if the emergency state was triggered and use different timer
		interrupt_counter = 0;											// Always reset the timer
		current_state = 0;												// Start at state_0
		if(emer_state == 0){
			display_emergency_mode(emer_state);
			emer_state = emer_state + 1;								// move to next state after done displaying
		}
		else if(emer_state == 1){
			display_emergency_mode(emer_state);
			emer_state = emer_state + 1;
		}
		else if(emer_state == 2){
			display_emergency_mode(emer_state);
			emer_state = emer_state + 1;
		}
		else if(emer_state == 3){										// loop around all states until out of emergency state
			display_emergency_mode(emer_state);
			emer_state = 0;
		}
	}

	/**
	 * FSM responsible for the night mode
	 * Is executed only if the value of the slide-switches is equal to 2
	 */
	if(trig_night == TRUE && interrupt_counter >= emer_timer) {	// Check if the night-mode state was triggered and use different timer
		interrupt_counter = 0;										// Always reset the timer
		current_state = 0;
		if(night_state == 0){										// Start at state_0
			display_night_mode(night_state);
			night_state = night_state + 1;							// move to next state after done displaying
		}
		else if(night_state == 1){
			display_night_mode(night_state);
			night_state = night_state + 1;
		}
		else if(night_state == 2){
			display_night_mode(night_state);
			night_state = night_state + 1;
		}
		else if(night_state == 3){
			display_night_mode(night_state);
			night_state = 0;										// loop around all states until out of emergency state
		}
	}
}


