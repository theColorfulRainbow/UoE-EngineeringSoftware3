/*
 * displaying_night_mode.c
 *
 *  Created on: Nov 13, 2018
 *      Author: Ilie
 */

#include "displaying_night_mode.h"

/**
 * FSM for the night-mode module
 * Is triggered once value from slide switches == 2
 * u16 state - the current state you are in
 */
void display_night_mode(u16 state) {
	switch(state){
		case 0:
			//                     VGA
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_yel);			// DISPLAY YELLOW TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_yel);			// DISPLAY YELLOW TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_yel);

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_yel + led_r_yel + led_p_red)); // DISPLAY YELLOW PEDESTRIAN LIGHT

			break;

		case 1: 														// DON'T DISPLAY ANYTHING = BLINK
			//                     VGA
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_nan);

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (/*led_l_yel + led_r_yel + led_p_red*/0));

			break;

		case 2:
			//                     VGA
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_yel);			// DISPLAY YELLOW TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_yel);			// DISPLAY YELLOW TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_yel);

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_yel + led_r_yel + led_p_red));	// DISPLAY YELLOW PEDESTRIAN LIGHT

			break;

		case 3:															// DON'T DISPLAY ANYTHING = BLINK
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
