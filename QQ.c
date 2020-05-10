/*
 * QQ.c
 *
 * Created: 08/05/2020 04:04:14 م
 *  Author: Genius
 */ 


#include <avr/io.h>
#include "LCD_ECU.h"
#include "Keypad.h"
#include "Data_type.h"
#include "TemperatureSensor.h"
#define F_CPU 8000000UL
#include <avr/delay.h>
#define EEPROM_PW1    0x05  
#define EEPROM_PW2    0x06
#define EEPROM_PW3    0x07
#define EEPROM_PW4    0x08
#define EEPROM_memory 0x09

int main(void)
{
	
	u8 flag =0;
	u8 arr [4];
	u8 NoOfTries=0;
	
	LCD_vInit(Eight_bit,High_Nibble,'b','a',5,'a',6,'a',7);
	Temp_Sensor_vInit(ADC0);
	keypad_vInit('c');
	LED_vintialize('d',7);
	LED_vintialize('d',0);
	LED_vintialize('d',6);
	LED_vintialize('d',5);
	LED_vintialize('d',4);
	u8 x,z,a;
	u16 m;
	
	if (EEPROM_Read(EEPROM_memory)==NOTPRESSED){
		
		LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"set PW:");
	do 
	{
		z=keypad_u8check_press('c');
	} while (z==NOTPRESSED);
	
	LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,z);
	_delay_ms(500);
	LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,8);
	LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,0x2A);
	_delay_ms(500);
		EEPROM_Write(EEPROM_PW1,z);
		z=NOTPRESSED;
		
		do
		{
			z=keypad_u8check_press('c');
		} while (z==NOTPRESSED);
		
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,z);
		_delay_ms(500);
		LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,9);
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,0x2A);
		_delay_ms(500);
		EEPROM_Write(EEPROM_PW2,z);
		z=NOTPRESSED;
		
		
		
		do
		{
			z=keypad_u8check_press('c');
		} while (z==NOTPRESSED);
		
		
		
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,z);
		_delay_ms(500);
		LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,10);
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,0x2A);
		_delay_ms(500);
		EEPROM_Write(EEPROM_PW3,z);
		z=NOTPRESSED;
		
		
		
		do
		{
			z=keypad_u8check_press('c');
		} while (z==NOTPRESSED);
		
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,z);
		_delay_ms(500);
		LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,11);
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,0x2A);
		_delay_ms(500);
		EEPROM_Write(EEPROM_PW4,z);
		z=NOTPRESSED;
		
		
		EEPROM_Write(EEPROM_memory,0x03);
		
		
	}		
	
	
	
	while (flag==0)
	{
		arr[1]=arr[0]=arr[3]=arr[2]=NOTPRESSED;
		LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
		LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"enter pw:");
		
		do
		{
			arr[0]=keypad_u8check_press('c');
		} while (arr[0]==NOTPRESSED);
		
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,arr[0]);
		_delay_ms(500);
		LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,10);
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,'*');
		_delay_ms(500);
		

		do
		{
			arr[1]=keypad_u8check_press('c');
		} while (arr[1]==NOTPRESSED);
		
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,arr[1]);
		_delay_ms(500);
		LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,11);
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,'*');
		_delay_ms(500);
		
		
		
		do
		{
			arr[2]=keypad_u8check_press('c');
		} while (arr[2]==NOTPRESSED);
		
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,arr[2]);
		_delay_ms(500);
		LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,12);
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,'*');
		_delay_ms(500);
		
		
		
		do
		{
			arr[3]=keypad_u8check_press('c');
		} while (arr[3]==NOTPRESSED);
		
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,arr[3]);
		_delay_ms(500);
		LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,13);
		LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,'*');
		_delay_ms(500);
		
		
		if (EEPROM_Read(EEPROM_PW1)==arr[0] && EEPROM_Read(EEPROM_PW2)==arr[1] && EEPROM_Read(EEPROM_PW3)==arr[2]&& EEPROM_Read(EEPROM_PW4)==arr[3])
		{
			flag=1;
			
			LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
			LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"correct pw");
			_delay_ms(500);
			
		}else{
			LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
			LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"wrong PW");
			_delay_ms(500);
			-- NoOfTries ;
			if (NoOfTries==3){
				LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"wait 15 seconds");
				_delay_ms(500);
			}
		}
	}			 
			
	
   
    	LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
       LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"1-light ");
	   LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,9);
	   LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"2-temp ");
	   LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,2,1);
		  LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"3-air condition ");
		  _delay_ms(00);
		  
		  
	   do {
		   x=keypad_u8check_press('c');
		  
	   }while (x==NOTPRESSED);
	   LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
	   LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"ur choice is ");
	   LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,x);
	   _delay_ms(500);
	   
	   if ('1'==x){
		  
		   LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
		   LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"light");
		   _delay_ms(500);
		    LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
		   LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"room 1,2,3,4");
		   _delay_ms(500);
		   
		  do {
			   m=keypad_u8check_press('c');
			   	   
	   }while(m==NOTPRESSED);
	   
	   
	   if(m=='1')	  { 
	   LED_vTurnon('d',4);
	   
	   LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
	   LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"room1");
	   
   }else  if(m=='2')	  {
	   LED_vTurnon('d',5);
	   LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
	   LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"room2");
   }	   
   else
    if(m=='3')	  {
	    LED_vTurnon('d',6);
		 LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
	    LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"room3");
    }
	 else  if(m=='4')	  {
		 LED_vTurnon('d',7);
		  LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
		 LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"room4");

	 }  else{
		 LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
		 LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"cant understand");
	 }
		 
	  
	   }else if (x=='2'){
		   LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
		   LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"temp");
		   m=Temp_Sensor_u16read(ADC0);
		   _delay_ms(100);
		   LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
		   LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"Temp=");
		   LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,7);
		   LCD_display_number(Eight_bit,High_Nibble,'b','a',5,'a',7,m);
		   LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,0xDF);
		   LCD_vsend_char(Eight_bit,High_Nibble,'b','a',5,'a',7,'C');
		   LCD_Move_Cursor(Eight_bit,High_Nibble,'b','a',5,'a',7,1,1);
		   
		   
    }
	else
	if (x=='3')
	{
		LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
		LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"air conditioning");
		LCD_clear_screen(Eight_bit,High_Nibble,'b','a',5,'a',7);
		LCD_vsend_string(Eight_bit,High_Nibble,'b','a',5,'a',7,"for on 1 ,off 0 ");
		a=keypad_u8check_press('c');
		if (a=='1'){
			LED_vTurnon('d',0);
			
		}else {
		
		}
		
		
	}
	while(1){}


	 }