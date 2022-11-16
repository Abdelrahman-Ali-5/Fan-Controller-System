/*
 * Mini_project3_test.c
 *
 *  Created on: Oct 6, 2022
 *      Author: Abdelrahman Ali Mohamed
 */

#include "lcd.h"
#include "DC_motor.h"
#include "adc.h"
#include "lm35_sensor.h"

int main() {

	uint8 temp; /* variable to save the reading of the sensor temperature */
	/* configure the adc module to operate with internal voltage 2.56 & prescaler F_CPU/8 */
	ADC_ConfigType ADC_configuration = { INTERNAL, PRESCALER_8 };
	/* initialization of LCD / DC_motor / ADC */
	LCD_init();
	DcMotor_init();
	ADC_init(&ADC_configuration);
	/* Display on the lcd */
	LCD_displayStringRowColumn(0, 2, "FAN is   ");
	LCD_displayStringRowColumn(1, 2, "TEMP is :   C");

	while (1) {

		temp = LM35_getTemperature();
		/*
		 * Check the temperature value and send the information to the DC_motor and PWM
		 * to rotate in which way & send the required speed of the FAN needed to the PWM
		 * */
		if (temp < 30) {
			LCD_moveCursor(0, 9);
			LCD_displayString("OFF");
			DcMotor_Rotate(STOP, OFF_0);
		}
		else if ((temp >= 30) && (temp < 60)) {
			DcMotor_Rotate(CW, QUARTER_25);
		}
		else if ((temp >= 60) && (temp < 90)) {
			DcMotor_Rotate(CW, HALF_50);
		}
		else if ((temp >= 90) && (temp < 120)) {
			DcMotor_Rotate(CW, QUARTER_AND_HALF_75);
		}
		else if (temp >= 120) {
			DcMotor_Rotate(CW, 100);
		}
		if (temp >= 30) {
			LCD_moveCursor(0, 9);
			LCD_displayString("ON ");
		}

		/* Moving the LCD cursor and continue to print the current temperature value */
		LCD_moveCursor(1, 11);
		if (temp >= 100) {
			LCD_intgerToString(temp);
		}
		else {
			LCD_intgerToString(temp);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
	}
}

