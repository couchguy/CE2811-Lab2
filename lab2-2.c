/*  **************************************************
	* FILENAME: lab2.c								 *
	* AUTHOR: Dan Kass kassd@msoe.edu    			 *
	* DATE: December 6, 2012						 *
	* CLASS: CE-2811 Lab 2 Professor Barnicki		 *
	* Provdies: 									 *
	*		Test program for the lcd.c file		 	 *
	*												 *
	************************************************** */

#include <avr/io.h>
#include <stdio.h>

#include "lcd.h"
#include <MSOE/delay.c>

int main(void)
{
	uint16_t delay = 2000;
	lcd_init();

	char test[] = "sample";
	char test2[] = "hey there";
	char custom[] = {0b00000000,
					 0b00000100,
					 0b00001010,
					 0b00011111,
					 0b00011111,
					 0b00001010,
					 0b00000100,
					 0b00000000};

	while(1){

		char *testPtr = test;
		char *test2Ptr = test2;
		char *customPtr = custom;

		//sends sample to the screen
		delay_ms(delay/4);
		lcd_string(testPtr);
		delay_ms(delay/4);
		//clears the screen
		lcd_ff();
		delay_ms(delay/2);
		//goes to position 0,5
		lcd_gotoxy(0, 5);
		//snets hey there to the sreen
		lcd_string(test2Ptr);
		delay_ms(delay/4);
		//goes back one char
		lcd_left();
		//sents 7 to the screen
		lcd_char('7');
		delay_ms(delay/4);
		//turns off the backlight
		lcd_backlight(OFF);
		delay_ms(delay/2);
		//turns on the the backlight
		lcd_backlight(ON);
		delay_ms(delay/4);
		//clears the screen
		lcd_clear();
		delay_ms(delay);
		//sends hey there to the screen
		lcd_string(test2Ptr);
		delay_ms(delay/2);
		//turns display off
		lcd_switch(OFF);
		delay_ms(delay/2);
		//turns display on
		lcd_switch(ON);
		delay_ms(delay/2);
		//clears the display
		lcd_clear();
		delay_ms(delay/2);
		//custom char
		lcd_define_char(3, customPtr);
		lcd_custom(3);
		delay_ms(delay);
		//clears the display
		lcd_clear();

	} //while
}//main
