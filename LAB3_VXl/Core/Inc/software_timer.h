/*
 * software_timer.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Dell
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int count[100];
extern int flag[100];

void setTimer(int, int);
void timer_run(int);

#endif /* INC_SOFTWARE_TIMER_H_ */
