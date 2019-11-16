/*
 *  main_traffic_lights.h
 *
 *  Created on: Nov 14, 2018
 *      Author: Ilie
 */

#ifndef SRC_MAIN_TRAFFIC_LIGHTS_H_
#define SRC_MAIN_TRAFFIC_LIGHTS_H_

#include "variables.h"
#include <stdio.h>
#include "xil_types.h"		// Added for integer type definitions
#include "gpio_init.h"

/**
 * FSM for the NORMAL TRAFFIC module
 * Is triggered once value from slide switches anything but 1 or 2
 * u16 state - the current state you are in
 */
void setState(u16 state);

#endif /* SRC_MAIN_TRAFFIC_LIGHTS_H_ */
