/*
 * displaying_night_mode_.h
 *
 *  Created on: Nov 13, 2018
 *      Author: Ilie
 */

#ifndef SRC_DISPLAYING_NIGHT_MODE_H_
#define SRC_DISPLAYING_NIGHT_MODE_H_

#include "variables.h"
#include <stdio.h>
#include "xil_types.h"		// Added for integer type definitions
#include "gpio_init.h"

/**
 * FSM for the night-mode module
 * Is triggered once value from slide switches == 2
 * u16 state - the current state you are in
 */
void display_night_mode(u16 state);

#endif /* SRC_DISPLAYING_NIGHT_MODE_H_ */
