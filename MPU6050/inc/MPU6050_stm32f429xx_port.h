/*
 * MPU6050_stm32f429xx_port.h
 *
 *  Created on: Oct 4, 2022
 *      Author: marco
 */

#ifndef API_INC_MPU6050_STM32F429XX_PORT_H_
#define API_INC_MPU6050_STM32F429XX_PORT_H_

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "API_delay.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"
#include "API_MPU6050.h"

bool_t I2C1ModuleInitPort();

void GPIOPinInitPort();

void MPUWritePort(uint8_t REG_ADDR, uint8_t data);

void MPUReadPort(uint8_t REG_ADDR, int8_t *value);

#endif /* API_INC_MPU6050_STM32F429XX_PORT_H_ */
