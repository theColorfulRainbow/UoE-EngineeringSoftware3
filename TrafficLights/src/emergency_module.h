/*
 * emergency_module.h
 *
 *  Created on: Nov 14, 2018
 *      Author: Ilie
 */

#ifndef SRC_EMERGENCY_MODULE_H_
#define SRC_EMERGENCY_MODULE_H_

#include "variables.h"
#include <stdio.h>
#include "xil_types.h"		// Added for integer type definitions
#include "gpio_init.h"

/**
 * FSM for the emergency module
 * Is triggered once value from slide switches == 1
 * u16 state - the current state you are in
 */
void display_emergency_mode(u16 state);


#endif /* SRC_EMERGENCY_MODULE_H_ */
