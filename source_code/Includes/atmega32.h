

#ifndef ATMEGA32_H_
#define ATMEGA32_H_

#include <avr/io.h>

// Define the clock frequency
#define F_CPU 16000000UL

//for LCD
#define LCD_DATA_PORT PORTA
#define LCD_CTRL_PORT PORTB
#define RS_PIN PINB2 //data bus to be treated as command
#define RW_PIN PINB1//set to read mode
#define E_PIN PINB0

#define FUNCTION_RESET 0x38
#define LCD_CLEAR 0b00000001
#define LCD_HOME 0b00000010
#define LCD_DISPLAY_ON_CURSOR_OFF 0b00001100
#define LCD_ENTRY_MODE 0b00000110


//For USART
#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

//For Motors
#define MOTOR_DRIVER_PORT PORTC

#endif /* ATMEGA32_H_ */