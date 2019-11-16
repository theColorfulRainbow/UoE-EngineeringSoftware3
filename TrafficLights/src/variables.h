/*
 * variables.h
 *
 *  Created on: Nov 13, 2018
 *      Author: Ilie
 */

#ifndef SRC_VARIABLES_H_
#define SRC_VARIABLES_H_

//#include "xgpio.h"

//=============================================================================================
//									VARAIBLES
//=============================================================================================

// Emergency mode states

#define emer_state_0   		0			// RED, 	RED, 	RED
#define emer_state_1   		1			// BLANK, 	BLANK, 	BALNK,
#define emer_state_2   		2			// BLUE, 	BLUE, 	BLUE
#define emer_state_3   		3			// BLANK, 	BLAN, 	BLANK,

//   Night mode states

#define night_state_0  		0			// YEL, 	YEL, 	YEL
#define night_state_1  		1			// BLANK, 	BLANK, 	BALNK,
#define night_state_2  		2			// YEL, 	YEL, 	YEL
#define night_state_3  		3			// BLANK, 	BLANK, 	BALNK,

// 		Colors

#define col_red  0b111100000000			// red     color used for the VGA
#define col_grn  0b000011110000			// green   color used for the VGA
#define col_blu  0b000000001111			// blue    color used for the VGA
#define col_yel  0b111111110000			// yellow  color used for the VGA
#define col_nan  0b111111111111			// blank   color used for the VGA

// States for the car traffic lights

#define state_0  	0					// RED, 		RED, 	RED
#define state_1 	1					// RED/YEL, 	RED, 	RED
#define state_2  	2					// GREEN, 		RED, 	RED
#define state_3  	3					// YEL, 		RED, 	RED
#define state_4  	4					// RED, 		RED, 	RED
#define state_5  	5					// RED, 		RED, 	RED/YEL
#define state_6  	6					// RED, 		RED, 	GREEN
#define state_7 	7					// RED, 		RED, 	RED

//    Pedestrian States

#define ped_state_0  	 0				// RED,		RED,	RED
#define ped_state_1  	 1				// RED,	    GREEN,	RED
#define ped_state_2 	 2				// RED,		BLANK,	RDE

//    Timer Limits

#define car_timer		 			500			// timer for the cars, 2s long
#define ped_timer  		 			1250		// timer for pedestrian used to display on the 7_seg_display, 5s long
#define ped_timer_3s  	 			750 		// timer for pedestrian to count up to 3s
#define ped_timer_blink  			50			// timer for pedestrian used to blink 0.2s each blink; 2s in total
#define display_timer_5s_setter  	1250		// timer for 5s used for pedestrian VGA
#define emer_timer  				100			// timer for emergency, 04s long
#define btn_r_timer 				250 		// timer used to check if right button is being pressed every second

//    LEDs

// Left Traffic Light

#define led_r_red  		1		// light up LED V16 = RED	 TRAFFIC LIGHT 1
#define led_r_yel  		2		// light up LED E19 = YELLOW TRAFFIC LIGHT 1
#define led_r_grn 		4		// light up LED V19 = GREEN	 TRAFFIC LIGHT 1

// Pedestrian Traffic Light

#define led_p_red 		 8		// light up LED W18 = RED 	PEDESTRIAN LIGHT
#define led_p_grn 		 16		// light up LED V15 = GREEN PEDESTRIAN LIGHT

// Right Traffic Light

#define led_l_red 		 32		// light up LED V14 = RED 	 TRAFFIC LIGHT 2
#define led_l_yel  		 64		// light up LED U14 = YELLOW TRAFFIC LIGHT 2
#define led_l_grn 		 128	// light up LED V13 = GREEN	 TRAFFIC LIGHT 2


#endif /* SRC_VARIABLES_H_ */
