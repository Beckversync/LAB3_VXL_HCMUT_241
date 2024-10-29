/*
 * System_FSM.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Dell
 */


#include "System_FSM.h"


int default_redlight;
int default_yellowlight;
int default_greenlight;

void SystemFSM(){
	switch(status){
		case INIT:
			if(is_button_pressed(0)){
				button1_press = 1;
			}
			if(!is_button_pressed(0) && button1_press){
				status = MODE1_NORMAL;
				setTimer(100, 0);
				setTimer(100, 1);
				// set default status for traffic light fsm
				TL1 = RED;
				TL2 = GREEN;

				// set default value time for traffic light fsm
				default_redlight = redlight;
				default_yellowlight = yellowlight;
				default_greenlight = greenlight;

				Red1 = default_redlight;
				Green2 = default_greenlight;
			}
			break;
		case MODE1_NORMAL:
			TrafficLightFSM1();
			TrafficLightFSM2();
			// press and release
			if(is_button_pressed(0)){
				button1_press = 1;
			}
			if(!is_button_pressed(0) && button1_press){
				status = MODE2_MANRED;
				setTimer(50, 3);
				button1_press = 0;
			}
			break;
		case MODE2_MANRED:
			// red led blinking 2HZ
			if(flag[3] == 1){
				setTimer(50, 3);
				HAL_GPIO_TogglePin(red1_GPIO_Port, red1_Pin);
				HAL_GPIO_TogglePin(red2_GPIO_Port, red2_Pin);
			}
			// 2 7SEG display value
			Updatebuffer(redlight, 1);
			// 2 7SEG display mode
			Updatebuffer(MODE2_MANRED, 2);
			// if button2 is pressed and released after that
			// increasing value by 1
			if(is_button_pressed(1)){
				button2_press = 1;
			}
			if(!is_button_pressed(1) && button2_press){
				redlight++;
				button2_press = 0;
			}
			// if button2 is pressed long 1s
			if(is_button_pressed_1s(1)){
				if(button2_first_press1s){
					setTimer(50, 4);
					button2_first_press1s = 0;
				}
				if(flag[4] == 1){
					setTimer(50, 4);
					redlight++;
				}
			}
			// if button3 is pressed, turn back to mode 1 normal
			if(is_button_pressed(2)){
				button3_press = 1;
			}
			if(!is_button_pressed(2) && button3_press){
				status = MODE1_NORMAL;
				// set timer for traffic light
				setTimer(100, 0);
				setTimer(100, 1);

				redlight = default_redlight;
				yellowlight = default_yellowlight;
				greenlight = default_greenlight;

				// turn off traffic light
				HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, SET);
				HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, SET);
				button3_press = 0;
			}
			// if button1 is pressed, go to next status
			if(is_button_pressed(0)){
				button1_press = 1;
			}
			if(!is_button_pressed(0) && button1_press){
				status = MODE3_MANYELLOW;
				// set timer for blinking led
				setTimer(50, 3);
				// turn off traffic light
				HAL_GPIO_WritePin(red1_GPIO_Port, red1_Pin, SET);
				HAL_GPIO_WritePin(red2_GPIO_Port, red2_Pin, SET);
				button1_press = 0;
			}
			break;
		case MODE3_MANYELLOW:
			// yellow led blinking 2HZ
			if(flag[3] == 1){
				setTimer(50, 3);
				HAL_GPIO_TogglePin(yellow1_GPIO_Port, yellow1_Pin);
				HAL_GPIO_TogglePin(yellow2_GPIO_Port, yellow2_Pin);
			}
			// 2 7SEG display value
			Updatebuffer(yellowlight, 1);
			// 2 7SEG display mode
			Updatebuffer(MODE3_MANYELLOW, 2);
			// if button2 is pressed and released after that
			// increasing value by 1
			if(is_button_pressed(1)){
				button2_press = 1;
			}
			if(!is_button_pressed(1) && button2_press){
				yellowlight++;
				button2_press = 0;
			}
			// if button2 is pressed long 1s
			if(is_button_pressed_1s(1)){
				if(button2_first_press1s){
					setTimer(50, 4);
					button2_first_press1s = 0;
				}
				if(flag[4] == 1){
					setTimer(50, 4);
					yellowlight++;
				}
			}
			// if button3 is pressed, turn back to mode 1 normal
			if(is_button_pressed(2)){
				button3_press = 1;
			}
			if(!is_button_pressed(2) && button3_press){
				status = MODE1_NORMAL;
				// set timer for traffic light
				setTimer(100, 0);
				setTimer(100, 1);

				redlight = default_redlight;
				yellowlight = default_yellowlight;
				greenlight = default_greenlight;

				// turn off traffic light
				HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, SET);
				HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, SET);
				button3_press = 0;
			}
			// if button1 is pressed, go to next status
			if(is_button_pressed(0)){
				button1_press = 1;
			}
			if(!is_button_pressed(0) && button1_press){
				status = MODE4_MANGREEN;
				// set timer for blinking led
				setTimer(50, 3);
				// turn off traffic light
				HAL_GPIO_WritePin(yellow1_GPIO_Port, yellow1_Pin, SET);
				HAL_GPIO_WritePin(yellow2_GPIO_Port, yellow2_Pin, SET);
				button1_press = 0;
			}
			break;
		case MODE4_MANGREEN:
			// green led blinking 2HZ
			if(flag[3] == 1){
				setTimer(50, 3);
				HAL_GPIO_TogglePin(green1_GPIO_Port, green1_Pin);
				HAL_GPIO_TogglePin(green2_GPIO_Port, green2_Pin);
			}
			// 2 7SEG display value
			Updatebuffer(greenlight, 1);
			// 2 7SEG display mode
			Updatebuffer(MODE4_MANGREEN, 2);
			// if button2 is pressed and released after that
			// increasing value by 1
			if(is_button_pressed(1)){
				button2_press = 1;
			}
			if(!is_button_pressed(1) && button2_press){
				greenlight++;
				button2_press = 0;
			}
			// if button2 is pressed long 1s
			if(is_button_pressed_1s(1)){
				if(button2_first_press1s){
					setTimer(50, 4);
					button2_first_press1s = 0;
				}
				if(flag[4] == 1){
					setTimer(50, 4);
					greenlight++;
				}
			}
			// if button3 is pressed, turn back to mode 1 normal
			if(is_button_pressed(2)){
				button3_press = 1;
			}
			if(!is_button_pressed(2) && button3_press){
				status = MODE1_NORMAL;
				// set timer for traffic light
				setTimer(100, 0);
				setTimer(100, 1);

				redlight = default_redlight;
				yellowlight = default_yellowlight;
				greenlight = default_greenlight;

				// turn off traffic light
				HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, SET);
				HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, SET);
				button3_press = 0;
			}
			// if button1 is pressed, go to next status
			if(is_button_pressed(0)){
				button1_press = 1;
			}
			if(!is_button_pressed(0) && button1_press){
				status = MODE1_NORMAL;
				// set timer for traffic light
				setTimer(100, 0);
				setTimer(100, 1);
				// turn off traffic light
				HAL_GPIO_WritePin(green1_GPIO_Port, green1_Pin, SET);
				HAL_GPIO_WritePin(green2_GPIO_Port, green2_Pin, SET);
				button1_press = 0;
			}
			break;
		default:
			break;
	}
}
