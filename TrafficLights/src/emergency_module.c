/*
 * emergency_module.c
 *
 *  Created on: Nov 14, 2018
 *      Author: Ilie
 */

#include "emergency_module.h"

/**
 * FSM for the emergency module
 * Is triggered once value from slide switches == 1
 * u16 state - the current state you are in
 */
void display_emergency_mode(u16 state) {
	switch(state){
		case 0:
			//                     VGA
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);						// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);						// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_red + led_p_red));	// DISPLAY RED PEDESTRIAN LIGHT

			break;

		case 1:																		// DON'T DISPLAY ANYTHING = BLINK
			//                     VGA
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_nan);

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (/*led_l_red + led_r_red + led_p_red*/0));

			break;

		case 2:
			//                     VGA
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_blu);							// DISPLAY BLUE TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_blu);							// DISPLAY BLUETRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_blu);

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_red + led_p_red));		// DISPLAY BLUE PEDESTRIAN LIGHT

			break;

		case 3:																			// DON'T DISPLAY ANYTHING = BLINK
			//                     VGA
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_nan);

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (/*led_l_red + led_r_red + led_p_red*/0));

			break;

	}
}
