	#ifndef Servo_H_
#define Servo_H_


#include <avr/io.h>
#include <util/delay.h>


void Servo_init();
void timer1_setup();
void Inc_step_s1 (int angle);
void Inc_step_s2 (int angle);
void Dec_step_s1 (int angle);
void Dec_step_s2 (int angle);
void servo1_angle(double value);
void servo2_angle(double value);
void init (void);

#endif /* Servo_H_*/
