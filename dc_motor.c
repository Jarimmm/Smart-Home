/*
 * dc_motor.c
 *
 *  Created on: Oct 4, 2024
 *      Author: Mariam Samy
 */
#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"
void DcMotor_Init(void){
	GPIO_setupPinDirection(DC_MOTOR_INT1_PORT,DC_MOTOR_INT1_PIN,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_INT2_PORT,DC_MOTOR_INT2_PIN,PIN_OUTPUT);
	GPIO_writePin(DC_MOTOR_INT1_PORT,DC_MOTOR_INT1_PIN,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_INT2_PORT,DC_MOTOR_INT2_PIN,LOGIC_LOW);

}

void DcMotor_Rotate(DcMotor_State state, uint8 speed){
	switch(state){
	case 0:
		GPIO_writePin(DC_MOTOR_INT1_PORT,DC_MOTOR_INT1_PIN,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_INT2_PORT,DC_MOTOR_INT2_PIN,LOGIC_LOW);
		break;
	case 1:
		GPIO_writePin(DC_MOTOR_INT1_PORT,DC_MOTOR_INT1_PIN,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_INT2_PORT,DC_MOTOR_INT2_PIN,LOGIC_HIGH);
		break;
	case 2:
		GPIO_writePin(DC_MOTOR_INT1_PORT,DC_MOTOR_INT1_PIN,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_INT2_PORT,DC_MOTOR_INT2_PIN,LOGIC_LOW);
	}
	PWM_Timer0_Start((uint32)speed*Compare_Pin_Max_value/DC_Motor_Max_speed);
}
