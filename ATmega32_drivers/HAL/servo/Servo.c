/*
 * Servo.c
 *
 * Created: 19/06/2022 21:19:09
 *  Author: Dina
 */ 
/*
 * IncFile1.h
 *
 * Created: 12/06/2022 08:54:22
 *  Author: Dina
 */ 

/*#include "Servo.h"



void Servo_init()
{
	 DDRD |= (1<<PD5);
	 DDRD |= (1<<PD4);
	//  Make OC1A pin as output  PD5
	 timer1_setup();
	
	
}
void timer1_setup()
{
	TCNT1 = 0;		// Set timer1 count zero
	ICR1 = 2499;		// Set TOP count for timer1 in ICR1 register
	

	// Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64
	TCCR1A = (1<<WGM11)|(1<<COM1A1)|(1<<COM1B1);
	TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
	OCR1A = 100;
	OCR1B = 500;
	
	
}


 void Inc_step_s1 (int angle)
 {
	 int inc_factor = (500*angle)/120;
	 
	 step1 = step1+inc_factor;
	  OCR1A = step1; 
	
 }
 
  void Inc_step_s2 (int angle)
  {
	
	int inc_factor = (500*angle)/120;
	
	step2 = step2+inc_factor;
	    OCR1B = step2;
	  
  }
 void Dec_step_s1 (int angle)
 {
	  
	
	int dec_factor = (500*angle)/120;
	step1 = step1-dec_factor;
	  OCR1A = step1;
 }
  void Dec_step_s2 (int angle)
  {
	  int dec_factor = (500*angle)/120;
	  
	  step2 = step2-dec_factor;
	    OCR1B = step2;
  }
*/

#include <avr/io.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

const float initial_angle_1 = 0.95;
const float initial_angle_2 = 1;

f32 temp_angle_1 ;
f32 temp_angle_2 ;

void servo1_angle(float value){

	OCR1A=500*value;
}
void servo2_angle(float value){

	OCR1B=500*value;
}

void init_Servos (void){
		temp_angle_1 = initial_angle_1;
		temp_angle_2 = initial_angle_2;
		SET_BIT(DDRD,5);
		SET_BIT(DDRD,4);
		SET_BIT(TCCR1A,COM1A1);
		SET_BIT(TCCR1A,COM1B1);
		SET_BIT(TCCR1A,WGM11);// fastpwm
		SET_BIT(TCCR1B,WGM12);// fastpwm
		SET_BIT(TCCR1B,WGM13);//fastpwm
		SET_BIT(TCCR1B,CS11);// prescaller /8
		ICR1=20000-1;

		servo1_angle(initial_angle_1*2);
		servo2_angle(initial_angle_2*2);
}

void Servo_2_operation(int angle, int direction)
 {

	 if (direction == 1 && angle == 90)

	 {
		 if ( (temp_angle_2 *= 2) < (initial_angle_2*4))
		{
		 temp_angle_2*=2;
		}

	 }
	 else if (direction == 0 && angle == 90)
	 {
		  if ((temp_angle_2/=2) > (initial_angle_2))
		  {
			  temp_angle_2/=2;
		  }
	 }
	  else if (direction == 1 && angle == 180)
	  {
		  if ((temp_angle_2*=4) < (initial_angle_2*4))
		  {
			  temp_angle_2*=4;
		  }
	  }
	   else if (direction == 0 && angle == 180)
	   {
		   if ((temp_angle_2/=4) > initial_angle_2)
		   {
			   temp_angle_2/=4;
		   }
	   }
	  servo2_angle(temp_angle_2 - 0.02);
 }

void Servo_1_operation(int angle, int direction)
	{

		if (direction == 1 && angle == 90)

		{
			if ((temp_angle_1*=2) < (initial_angle_1*4))
			{
				temp_angle_1*=2;
			}

		}
		else if (direction == 0 && angle == 90)
		{
			if ((temp_angle_1/=2) > (initial_angle_1))
			{
				temp_angle_1/=2;
			}
		}
		else if (direction == 1 && angle == 180)
		{
			if ((temp_angle_1*=4) < (initial_angle_1*4))
			{
				temp_angle_1*=4;
			}
		}
		else if (direction == 0 && angle == 180)
		{
			if ((temp_angle_1/=4) > initial_angle_1)
			{
				temp_angle_1/=4;
			}
		}
   servo1_angle(temp_angle_1 - 0.02);
}
