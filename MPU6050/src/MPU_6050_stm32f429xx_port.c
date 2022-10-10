/*
 * MPU_6050_stm32f429xx_port.c
 *
 *  Created on: Oct 4, 2022
 *      Author: marco
 */
#include "MPU6050_stm32f429xx_port.h"

#define I2C_ADDR (MPU6050_ADDR << 1)

static I2C_HandleTypeDef I2C1Handler;


bool_t I2C1ModuleInitPort(){
	I2C1Handler.Instance = I2C1;
	I2C1Handler.Init.ClockSpeed = 100000;
	I2C1Handler.Init.DutyCycle = I2C_DUTYCYCLE_2;
	I2C1Handler.Init.OwnAddress1 = 0;
	I2C1Handler.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
	I2C1Handler.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
	I2C1Handler.Init.OwnAddress2 = 0;
	I2C1Handler.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
	I2C1Handler.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
	__I2C1_CLK_ENABLE();
	if (HAL_I2C_Init(&I2C1Handler) != HAL_OK)
	{
		return false;
	}

	/** Configure Analogue filter
	 */
	if (HAL_I2CEx_ConfigAnalogFilter(&I2C1Handler, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
	{
		return false;
	}

	/** Configure Digital filter
	 */
	if (HAL_I2CEx_ConfigDigitalFilter(&I2C1Handler, 0) != HAL_OK)
	{
		return false;
	}
	/* USER CODE BEGIN I2C1_Init 2 */
	return true;
	/* USER CODE END I2C1_Init 2 */

}

void GPIOPinInitPort(){

	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_9;
	GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
	GPIO_InitStruct.Pull = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FAST;
	GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;

	__GPIOB_CLK_ENABLE();
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void MPUWritePort(uint8_t REG_ADDR, uint8_t data){
	HAL_I2C_Mem_Write(&I2C1Handler, I2C_ADDR, REG_ADDR, 1, &data, 1, MAX_TIMEOUT_MS);
}

void MPUReadPort(uint8_t REG_ADDR, int8_t *value){
	HAL_I2C_Mem_Read(&I2C1Handler, I2C_ADDR, REG_ADDR, 1, value, 1, MAX_TIMEOUT_MS);
}
