/*
 * display_timer.h
 *
 *  Created on: Nov 13, 2018
 *      Author: Ilie
 */

#ifndef SRC_DISPLAY_TIMER_H_
#define SRC_DISPLAY_TIMER_H_

#include "variables.h"
#include "xil_types.h"

/**
 *  FSM for displaying time on the 7_seg_display
 *	u16 counter 	 - value of the interrupt counter
 *	u16 return value - returns what digit should be displayed on the 7_seg_display
 */
u16 displayTime(u16 counter);


#endif /* SRC_DISPLAY_TIMER_H_ */
