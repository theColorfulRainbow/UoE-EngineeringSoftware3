

#include <stdio.h>
#include "xil_types.h"		// Added for integer type definitions
#include "gpio_init.h"
#include "pedestrain_methods.h"

/**
 * FSM for the NORMAL TRAFFIC module
 * Is triggered once the left button is pressed
 * u16 state - the current state you are in
 */
void movePedestrian(u16 state) {

	switch(state) {
		case 0:
			//						VGA
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_red);							// DISPLAY RED PEDESTRAIN LIGHT 1

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_red + led_p_red));

			break;

		case 1:
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_grn);							// DISPLAY GREEN PEDESTRIAN LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_red + led_p_grn));

			break;

		case 2:
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_grn);							// DISPLAY GREEN PEDESTRIAN LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_red + led_p_grn));

			break;

		case 3:
			XGpio_DiscreteWrite(&REG_0_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 1
			XGpio_DiscreteWrite(&REG_6_COLOUR_OUT, 1, col_red);							// DISPLAY RED TRAFFIC LIGHT 2

			XGpio_DiscreteWrite(&REG_1_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_7_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_2_COLOUR_OUT, 1, col_nan);
			XGpio_DiscreteWrite(&REG_8_COLOUR_OUT, 1, col_nan);

			XGpio_DiscreteWrite(&REG_4_COLOUR_OUT, 1, col_nan);							// DISPLAY BLANK PEDESTRIAN LIGHT

			//						LEDs
			XGpio_DiscreteWrite(&LED_OUT, 1, (led_l_red + led_r_red + led_p_red));

			break;

	}
}
