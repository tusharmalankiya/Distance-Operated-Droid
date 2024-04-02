
#include "lcd.h"
#include <util/delay.h>


//when in command mode
void LCD_command(unsigned char command){
	LCD_DATA_PORT = command;
	LCD_CTRL_PORT &= ~(1<<RS_PIN);//RS 0(command mode)
	LCD_CTRL_PORT&=~(1<<RW_PIN);//RW 0 (write mode)
	LCD_CTRL_PORT |= (1<<E_PIN); //enable high
	_delay_ms(1);
	LCD_CTRL_PORT &= ~(1<< E_PIN); //enable low
	_delay_ms(1);
	
}

//CLEAR SCREEN
void Lcd_clear_screen(void){
	LCD_command(LCD_CLEAR);
	_delay_ms(2);
}

//initialize LCD
void LCD_init(){
	_delay_ms(15);
	LCD_command(FUNCTION_RESET);
	_delay_ms(5);
	LCD_command(FUNCTION_RESET);
	_delay_ms(120);
	LCD_command(FUNCTION_RESET);
	LCD_command(FUNCTION_RESET);
	LCD_command(LCD_DISPLAY_ON_CURSOR_OFF);
	LCD_command(LCD_CLEAR);
	_delay_ms(2);
	LCD_command(LCD_ENTRY_MODE);
	_delay_ms(5);
}

//when in data mode
void LCD_data(unsigned char data){
	LCD_DATA_PORT = data;
	LCD_CTRL_PORT |= (1<<RS_PIN);//RS 1(character data mode)
	LCD_CTRL_PORT &= ~(1<<RW_PIN);//RW 0 (write mode)
	LCD_CTRL_PORT |= (1<<E_PIN); //enable high
	_delay_ms(1);
	LCD_CTRL_PORT &= ~(1<< E_PIN); //enable low
	_delay_ms(1);
	
}

//passing string
void LCD_string(char *str){
	int a = 1;
	while(*str){
		LCD_data(*str++);
		_delay_ms(2);
		//LCD_command(0b00011100);//display shift right
		//_delay_ms(1);
		if(a==16){
			LCD_command(0xC0);
			_delay_ms(2);
			
		}
		if(a==32){
			a=1;
			LCD_command(LCD_CLEAR);
			_delay_ms(2);
		}
		a++;
	}
	//LCD_command(0b00011000); //left shift
	//_delay_ms(1);
	
}