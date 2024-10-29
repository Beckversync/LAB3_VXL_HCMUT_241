/*
 * software_timer.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Dell
 */


#include "software_timer.h"

int count[100];
int flag[100];

void setTimer(int duration, int index){
	flag[index] = 0;
	count[index] = duration;
}

void timer_run(int index){
	if(count[index] > 0){
		count[index]--;
		if(count[index] <= 0){
			flag[index] = 1;
		}
	}
}
