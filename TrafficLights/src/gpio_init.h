#ifndef __GPIO_INIT_H_
#define __GPIO_INIT_H_

#include "xgpio.h"		// Added for xgpio object definitions

XStatus initGpio(void);

XGpio SEG7_HEX_OUT;			// 7 SEG Display digit displayed
XGpio SEG7_SEL_OUT;			// 7 SEG Display Region Selector
XGpio P_BTN_LEFT;			// LEFT BUTTON
XGpio P_BTN_RIGHT;			// RIGHT BUTTON
XGpio LED_OUT;				// 16  LEDs on the board
XGpio SLIDE_SWITCHES;		// SLIDE SWITCHES value
XGpio P_BTN_DOWN;			// DOWN BUTTON

// VGA
XGpio VGA_COLOUR;
XGpio VGA_REGION;

// REGION_COLOR
XGpio REG_0_COLOUR_OUT;		// Region color 0
XGpio REG_1_COLOUR_OUT;		// Region color 1
XGpio REG_2_COLOUR_OUT;		// Region color 2
XGpio REG_3_COLOUR_OUT;		// Region color 3
XGpio REG_4_COLOUR_OUT;		// Region color 4
XGpio REG_5_COLOUR_OUT;		// Region color 5
XGpio REG_6_COLOUR_OUT;		// Region color 6
XGpio REG_7_COLOUR_OUT;		// Region color 7
XGpio REG_8_COLOUR_OUT;		// Region color 8
XGpio REG_9_COLOUR_OUT;		// Region color 9
XGpio REG_10_COLOUR_OUT;	// Region color 10
XGpio REG_11_COLOUR_OUT;	// Region color 11
XGpio REG_12_COLOUR_OUT;	// Region color 12

#endif
