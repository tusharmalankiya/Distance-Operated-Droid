/*
 * Atmel.c
 *
 * Created: 4/2/2024 3:58:04 PM
 * Author : Tushar Malankiya
 */ 

#include "./Libraries/LCD/lcd.h"
#include "./Libraries/USART/usart.h"
#include "./Methods/methods.h"

#include <util/delay.h>



void RobotLogic(char res){
	Lcd_clear_screen();
	switch (res)
	{
		case '7':
		LCD_string("L Forward");
		USART_transmition_string("\r\nL Forward\r\n");
		Left_wheel_forward();
		break;
		case '1':
		LCD_string("L Reverse");
		USART_transmition_string("\r\nL Reverse\r\n");
		Left_wheel_reverse();
		break;
		case '9':
		LCD_string("RF");
		USART_transmition_string("\r\nRF\r\n");
		right_wheel_forward();
		break;
		case '3':
		LCD_string("RR");
		USART_transmition_string("\r\nRR\r\n");
		right_wheel_reverse();
		break;
		case '4':
		LCD_string("LS");
		USART_transmition_string("\r\nLS\r\n");
		Left_wheel_stop();
		break;
		case '6':
		LCD_string("RS");
		USART_transmition_string("\r\nRS\r\n");
		right_wheel_stop();
		break;
		default:
		LCD_string("STOP");
		USART_transmition_string("\r\nSTOP\r\n");
		stop();
		break;
	}
}

//-------INDICATORS-------------------
void robot_status(int i){
	if(i == 1){
		PORTB |= (1<< PINB3);
	}else{
		PORTB &= ~(1<< PINB3);
	}
}

void indicates_transmission(void){
	PORTD |= (1<< PIND3);
	_delay_ms(300);
	PORTD &= ~(1 << PIND3);
}

int main(void)
{
	
	DDRC = 0XFF; //Motor drive
	DDRA = 0xFF; //DATA bus
	DDRB = 0xFF; //control bus
	
	//set output for PIND3
	DDRD = 0b00001000;
	
	//initiallly robot indicates off
	robot_status(0);
	
	//initializing LCD
	LCD_init();
	
	LCD_string("START");
	
	//initializing USART
	USART_init();
	//transmitting String
	USART_transmition_string("Ready?");
	
	//indicate robot to be ON
	robot_status(1);
	
	
    while (1) 
    {
		//receiving characters
		char response = USART_receive();
		//indicating transmission 
		indicates_transmission();
		
		RobotLogic(response);
			
    }
	robot_status(0);
}

