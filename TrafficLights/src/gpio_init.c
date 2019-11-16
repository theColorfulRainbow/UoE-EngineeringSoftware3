#include "gpio_init.h"

XStatus initGpio(void)
{
	XStatus status;

	/* Note that all the required Xgpio objects
	 * have been declared in the gpio_init.h header file
	 * but make sure you confirm that the IDs used to initialize
	 * the GPIOs here are correct
	 */
	status = XGpio_Initialize(&SEG7_HEX_OUT, 0);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&SEG7_SEL_OUT, 1);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}
	
	status = XGpio_Initialize(&P_BTN_LEFT, 4);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&P_BTN_RIGHT, 5);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&P_BTN_DOWN, 3);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&SLIDE_SWITCHES, 19);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&LED_OUT, 2);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	// << Complete the XGpio initialization >>

//=====================================================================================================
//									VGA
//=====================================================================================================
	status = XGpio_Initialize(&VGA_REGION, 10);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&VGA_COLOUR, 8);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

//=====================================================================================================
//								REGION_COLOR
//=====================================================================================================
	status = XGpio_Initialize(&REG_0_COLOUR_OUT, 7);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&REG_10_COLOUR_OUT, 8);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&REG_11_COLOUR_OUT, 9);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&REG_1_COLOUR_OUT, 10);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&REG_2_COLOUR_OUT, 11);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&REG_3_COLOUR_OUT, 12);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&REG_4_COLOUR_OUT, 13);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}


	status = XGpio_Initialize(&REG_5_COLOUR_OUT, 14);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}


	status = XGpio_Initialize(&REG_6_COLOUR_OUT, 15);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&REG_7_COLOUR_OUT, 16);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&REG_8_COLOUR_OUT, 17);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	status = XGpio_Initialize(&REG_9_COLOUR_OUT, 18);
	if (status != XST_SUCCESS)
	{
		return XST_FAILURE;
	}

	return XST_SUCCESS;
}
