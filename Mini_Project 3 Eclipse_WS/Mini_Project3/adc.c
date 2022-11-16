 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the ATmega16 ADC driver
 *
 * Author: Abdelrahman Ali Mohamed
 *
 *******************************************************************************/

#include "avr/io.h" /* To use the ADC Registers */
#include "adc.h"
#include "common_macros.h" /* To use the macros like SET_BIT */

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	/* ADMUX Register Bits Description:
	 * Configure the register with the reference voltage passed to the struct
	 */
	ADMUX = (ADMUX & 0x3F) | (( Config_Ptr -> ref_volt) << 6);

	/* ADCSRA Register Bits Description:
	 * Configure the register with the prescaler value passed to the struct
	 */
	ADCSRA = (ADCSRA & 0xF8) | (Config_Ptr -> prescaler_value);
	/*
	 * Enable ADC
	 * */
	ADCSRA |= (1<<ADEN);
}

uint16 ADC_readChannel(uint8 channel_num)
{
	/*
	 * Clear first 5 bits in the ADMUX (channel number MUX4:0 bits) before set the required channel
	 * Choose the correct channel by setting the channel number in MUX4:0 bits
	 * Insert channel number into register ADMUX
	 */
	ADMUX |= (ADMUX & 0xE0) |(channel_num & 0x07);
	SET_BIT(ADCSRA,ADSC); /* Start conversion write '1' to ADSC */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)); /* Wait for conversion to complete, ADIF becomes '1' */
	SET_BIT(ADCSRA,ADIF); /* Clear ADIF by write '1' to it :) */
	return ADC; /* Read the digital value from the data register */
}
