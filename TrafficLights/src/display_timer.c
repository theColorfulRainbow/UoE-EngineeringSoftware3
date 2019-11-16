
#include "display_timer.h"
/**
 *  FSM for displaying time on the 7_seg_display
 *	u16 counter 	 - value of the interrupt counter
 *	u16 return value - returns what digit should be displayed on the 7_seg_display
 */
u16 displayTime(u16 counter) {
	if(counter > 1000 && counter <= 1250) {
		return 5;
	}
	else if(counter > 750 && counter <= 1000) {
		return 4;
	}
	else if(counter > 500 && counter <= 750) {
		return 3;
	}
	else if(counter > 250 && counter <= 500) {
		return 2;
	}
	else if(counter > 0&& counter <= 250) {
		return 1;
	}
	else if(counter == 0) {
		return 0;
//		display_seg = FALSE;
//		display_timer_5s = 1250;
	}
}
