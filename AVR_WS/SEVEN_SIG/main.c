/*
 * main.c
 *
 *  Created on: Sep 11, 2021
 *      Author: ziad
 */
#include"avr/io.h"
#include"util/delay.h"

void main(void)
{
DDRA = 0b11111111 ;
DDRC = 0b11111111;
//PORTC = 0b00000001;
char segment[10]={0b00111111 ,0b00000110, 0b01011011 ,0b01001111 ,0b01100110 ,0b01101101 , 0b01111101,0b00000111 ,0b01111111 ,  0b01101111};

while(1)
 {
	for(int i=0 ; i<10 ;i ++)
    {

		for(int j=0 ; j<10 ; j++)
    	{
    		for(long k =0 ;k<350;k++)
    		{
    			for(int e=0 ;e<10 ;e++)
    			{
    			   PORTC=0b11111110;
    			   PORTA = segment[j];
    		    }
    			for(int f=0 ;f<100 ; f++)
    			{
    			   PORTC= 0b11111101;
    			  PORTA = segment[i];
    			}
    		}

        }
     }


 }


}
