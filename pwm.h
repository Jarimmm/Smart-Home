/*
 * pmw.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */

#ifndef PWM_H_
#define PWM_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define Compare_Pin_PORT PORTB_ID
#define Compare_Pin_PIN  PIN3_ID
#define Compare_Pin_Max_value 255
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for generation PWM signals with different duty cycle
 * .it takes the duty cycle determined as a function argument
 */
void PWM_Timer0_Start(uint8 duty_cycle);

#endif /* PWM_H_ */
