/*
 * pedestrain_methods.h
 *
 *  Created on: Nov 13, 2018
 *      Author: Ilie
 */

#ifndef SRC_PEDESTRAIN_METHODS_H_
#define SRC_PEDESTRAIN_METHODS_H_

#include "variables.h"
#include "xgpio.h"

/**
 * FSM for the NORMAL TRAFFIC module
 * Is triggered once the left button is pressed
 * u16 state - the current state you are in
 */
void movePedestrian(u16 state);

#endif /* SRC_PEDESTRAIN_METHODS_H_ */
