
#ifndef LCD_H_
#define LCD_H_

#include "./../../Includes/atmega32.h"


//when in command mode
void LCD_command(unsigned char command);

//CLEAR SCREEN
void Lcd_clear_screen(void);

//initialize LCD
void LCD_init();

//when in data mode
void LCD_data(unsigned char data);

//passing string
void LCD_string(char *str);

#endif /* LCD_H_ */