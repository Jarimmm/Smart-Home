/*
 * buzzer.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */

#ifndef BUZZER_H_
#define BUZZER_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define BUZZER_PORT_num PORTD_ID
#define BUZZER_PIN_num PIN3_ID
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialization for the Buzzer driver
 */
void Buzzer_init(void);
/*
 * Description :
 * Function responsible for setting the Buzzer on.
 */
void Buzzer_on(void);
/*
 * Description :
 * Function responsible for setting the Buzzer off.
 */
void Buzzer_off(void);
#endif /* BUZZER_H_ */
