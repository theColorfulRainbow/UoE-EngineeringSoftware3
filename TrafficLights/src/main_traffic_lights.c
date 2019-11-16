/*
 * main_traffic_lights.c
 *
 *  Created on: Nov 13, 2018
 *      Author: Ilie
 */

#include "main_traffic_lights.h"

/**
 * FSM for the NORMAL TRAFFIC module
 * Is triggered once value from slide switches anything but 1 or 2
 * u16 state - the current state you are in
 */
void setState(u16 state) {
	switch(state){
		case 0:
			// 					VGA Regions
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);							// DISPLAY RED PEDESTRIAN LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_red + led_p_red));		// DISPLAY LEDS

			break;

		case 1:
			// 					VGA Regions
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_yel);							// DISPLAY YELLOW TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);							// DISPLAY RED PEDESTRIAN LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_l_yel + led_r_red + led_p_red));	// DISPLAY LEDS

			break;

		case 2:
			// 					VGA Regions
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_grn);							// DISPLAY GREEN TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);							// DISPLAY RED PEDESTRIAN LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_grn+ led_r_red + led_p_red));		// DISPLAY LEDS

			break;



		case 3:
			// 					VGA Regions
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_yel);							// DISPLAY YELLOW TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);							// DISPLAY RED PEDESTRIAN LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_yel + led_r_red + led_p_red));		// DISPLAY LEDS

			break;

		case 4:
			// 					VGA Regions
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);							// DISPLAY RED PEDESTRIAN LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_red + led_p_red));		// DISPLAY LEDS

			break;

		case 5:
			// 					VGA Regions
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_yel);							// DISPLAY YELLOW TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);							// DISPLAY RED PEDESTRIAN LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_red + led_r_yel + led_p_red));	// DISPLAY LEDS

			break;

		case 6:
			// 					VGA Regions
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_grn);							// DISPLAY GREEN TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);							// DISPLAY PEDESTRIAN TRAFFIC LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_grn+ led_p_red));		// DISPLAY LEDS

			break;

		case 7:
			// 					VGA Regions
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_yel);							// DISPLAY YELLOW TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);							// DISPLAY RED PEDESTRAIN  LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_yel+ led_p_red));		// DISPLAY LEDS

			break;

		default:
			// 					VGA Regions
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);							// DISPLAY RED PEDESTRIAN LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_red + led_p_red));		// DISPLAY LEDS

			break;
	}
}
