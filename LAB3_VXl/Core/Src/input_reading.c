/*
 * input_reading.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Dell
 */


#include "input_reading.h"

#define NO_OF_BUTTONS	3

#define DURATION_FOR_AUTO_INCREASING	100
#define BUTTON_IS_PRESSED				GPIO_PIN_RESET
#define BUTTON_IS_RELEASED				GPIO_PIN_SET

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];

static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];

static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];

static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];


void InitButton(){
	for(unsigned char i = 0; i < NO_OF_BUTTONS; i ++){
		debounceButtonBuffer1[i] = BUTTON_IS_RELEASED;
		debounceButtonBuffer2[i] = BUTTON_IS_RELEASED;
		buttonBuffer[i] = BUTTON_IS_RELEASED;
	}
}
void button_reading(unsigned char index){
	debounceButtonBuffer2[index] = debounceButtonBuffer1[index];
	if(index == 0){
		debounceButtonBuffer1[index] = HAL_GPIO_ReadPin(button1_GPIO_Port, button1_Pin);
	}
	else if(index == 1){
		debounceButtonBuffer1[index] = HAL_GPIO_ReadPin(button2_GPIO_Port, button2_Pin);
	}
	else{
		debounceButtonBuffer1[index] = HAL_GPIO_ReadPin(button3_GPIO_Port, button3_Pin);
	}

	if(debounceButtonBuffer1[index] == debounceButtonBuffer2[index]){
		buttonBuffer[index] = debounceButtonBuffer1[index];
		if(debounceButtonBuffer1[index] == BUTTON_IS_PRESSED){
			if(counterForButtonPress1s[index] < DURATION_FOR_AUTO_INCREASING){
				counterForButtonPress1s[index]++;
			}
			else{
				flagForButtonPress1s[index] = 1;
			}
		}
		else{
			counterForButtonPress1s[index] = 0;
			flagForButtonPress1s[index] = 0;
		}
	}
}

unsigned char is_button_pressed(uint8_t index){
	if(index >= NO_OF_BUTTONS) return 0;
	return (buttonBuffer[index] == BUTTON_IS_PRESSED);
}

unsigned char is_button_pressed_1s(unsigned char index){
	if(index >= NO_OF_BUTTONS) return 0;
	return (flagForButtonPress1s[index] == 1);
}
