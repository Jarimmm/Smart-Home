/*
 * dc_motor.h
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_
#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_INT1_PORT PORTB_ID
#define DC_MOTOR_INT1_PIN  PIN0_ID
#define DC_MOTOR_INT2_PORT PORTB_ID
#define DC_MOTOR_INT2_PIN  PIN1_ID
#define DC_MOTOR_ENABLE_PORT PORTB_ID
#define DC_MOTOR_ENABLE_PIN  PIN3_ID
#define DC_Motor_Max_speed 100
typedef enum
{
	Stop,CW,ACW
}DcMotor_State;
/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
/*
 * Description :
 * Function responsible for initialization for the DC Motor
 */
void DcMotor_Init(void);
/*
 * Description :
 * Function responsible for making the motor work with a given speed and state CW,A-CW,Stop
 */
void DcMotor_Rotate(DcMotor_State state, uint8 speed);
#endif /* DC_MOTOR_H_ */
