#include "methods.h"

#include "./../Includes/atmega32.h"

void Left_wheel_forward(void){
	PORTC |= (1<<PINC0);
	PORTC &= ~(1<< PINC1);
}

void right_wheel_forward(void){
	PORTC |= (1<<PINC2);
	PORTC &= ~(1<< PINC3);
}


void Left_wheel_reverse(void){
	PORTC &= ~(1<<PINC0);
	PORTC |= (1<< PINC1);
}


void right_wheel_reverse(void){
	PORTC &= ~(1<<PINC2);
	PORTC |= (1<< PINC3);
}

void Left_wheel_stop(void){
	PORTC |= (1<<PINC0);
	PORTC |= (1<< PINC1);
}

void right_wheel_stop(void){
	PORTC |= (1<<PINC2);
	PORTC |= (1<< PINC3);
}

void stop(void){
	PORTC |= (1<<PINC0);
	PORTC |= (1<< PINC1);
	PORTC |= (1<<PINC2);
	PORTC |= (1<< PINC3);
}