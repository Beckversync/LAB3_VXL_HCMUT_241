/*
 * global.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Dell
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define Internalclock 8000000
#define Onesecond 1000

extern int prescaler;
extern int period;
extern int time_cycle;
extern int id;
extern int button1_press;
extern int button2_press;
extern int button3_press;
extern int button2_first_press1s;

enum State { INIT, MODE1_NORMAL, MODE2_MANRED, MODE3_MANYELLOW,
	MODE4_MANGREEN
};

enum TrafficLight { GREEN, YELLOW, RED };

extern int status;

extern int TL1;
extern int TL2;

extern int redlight;
extern int yellowlight;
extern int greenlight;

extern int Red1;
extern int Green1;
extern int Yellow1;

extern int Red2;
extern int Green2;
extern int Yellow2;

#endif /* INC_GLOBAL_H_ */
