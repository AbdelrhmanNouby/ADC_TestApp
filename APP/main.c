/*
 * ADC_TestApp.c
 *
 *  Created on: Jan 22, 2022
 *      Author: Abdelrhman Elsawy
 */


/*
 4 level app measure volt in pin and turn led for each level 
 */

#include "../ECUAL/LED/LED.h"
#include "../MCAL/ADC/ADC_interface.h"

LED_t led1 = {PORTB,PIN4};
LED_t led2 = {PORTB,PIN5};
LED_t led3 = {PORTB,PIN6};
LED_t led4 = {PORTB,PIN7};
ADCChannel_t POT = { PORTA , PIN0 , ADC_SINGLE_CONVERSION } ;
	
int main(void)
{
	DIO_u8SetPinDirection ( PORTA , PIN0 , INPUTPIN ) ;
	LED_u8Init(led1);
	LED_u8Init(led2);
	LED_u8Init(led3);
	LED_u8Init(led4);
	ADC_u8Init();
	uint16_t u16Reading = 0 ;
    while (1) 
    {
		ADC_u8StartConversion( &POT ) ;
		ADC_u8GetRead( &u16Reading );
		if ( u16Reading < 256 )
		{
			LED_u8On(led1); 
			LED_u8Off(led2); 
			LED_u8Off(led3);
			LED_u8Off(led4); 
		}
		else if ( u16Reading < 512 )
		{
			LED_u8On(led1);
			LED_u8On(led2);
			LED_u8Off(led3);
			LED_u8Off(led4);
		}
		else if ( u16Reading < 768 )
		{
			LED_u8On(led1);
			LED_u8On(led2);
			LED_u8On(led3);
			LED_u8Off(led4);
		}
		else if ( u16Reading < 1024 )
		{
			LED_u8On(led1);
			LED_u8On(led2);
			LED_u8On(led3);
			LED_u8On(led4);
		}
    }
}

