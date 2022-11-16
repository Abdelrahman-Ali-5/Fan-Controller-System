 /******************************************************************************
 *
 * Module: PWM
 *
 * File Name: PWM.h
 *
 * Description: Header file for the AVR PWM driver
 *
 * Author: Abdelrahman Ali Mohamed
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "gpio.h"


/*******************************************************************************
 *                               Typedef Definitions                                  *
 *******************************************************************************/


typedef enum {
	OFF_0,QUARTER_25 = 0x19,HALF_50 = 0x32 ,QUARTER_AND_HALF_75 = 0x4B ,MAX_100 = 0x64
}Fan_speeds;

/*******************************************************************************
 *                               Definitions                                  *
 *******************************************************************************/

#define OC0_PORT PORTB_ID
#define OC0_PIN PIN3_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description:
 * Generate a PWM signal with frequency 500Hz
 * Timer0 will be used with pre-scaler F_CPU/8
 * F_PWM=(F_CPU)/(256*N) = (10^6)/(256*8) = 500Hz
 * Duty Cycle can be changed by updating the value
 * in The Compare Register
 */

void Timer0_PWM_Init(uint8 duty_cycle);


#endif /* PWM_H_ */
