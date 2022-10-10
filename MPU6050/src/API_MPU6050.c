/*
 * API_uart.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Marco Scasserra
 */

#ifndef API_INC_API_UART_H_
#define API_INC_API_UART_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "API_MPU6050.h"
#include "API_delay.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"
#include "MPU6050_stm32f429xx_port.h"

static float readGyroX();
static float readGyroY();
static float readGyroZ();
static float readAccelX();
static float readAccelY();
static float readAccelZ();

const float ACCEL_SENSITIVITY[4] = {
		16384.0,
		8192.0,
		4096.0,
		2048.0};

const float GYRO_SENSITIVITY[4] = {
		131.0,
		65.5,
		32.8,
		16.4};

/* Exported functions --------------------------------------------------------*/

bool_t MPU6050Init(){
	I2C1ModuleInitPort();
	GPIOPinInitPort();

	MPUWritePort(PWR_MGMT_1, PWR_CONFIG);
	MPUWritePort(SMPRT_DIV, SMPRT_CONFIG);
	MPUWritePort(GYRO_CONFIG, GYRO_SMPRT);
	MPUWritePort(ACCEL_CONFIG, ACCEL_SMPRT);
	return true;
}

void readGyro(gyroValues_t *gyroMeasure){
	gyroMeasure->gyroX = readGyroX();
	gyroMeasure->gyroY = readGyroY();
	gyroMeasure->gyroZ = readGyroZ();
}

void readAccel(accelValues_t *accelMeasure){
	accelMeasure->accelX = readAccelX();
	accelMeasure->accelY = readAccelY();
	accelMeasure->accelZ = readAccelZ();
}

void readTemp(float *tempMeasure){
	int8_t dataH_RAW = 0, dataL_RAW = 0;
	int16_t returnValue_RAW = 0;
	MPUReadPort(TEMP_OUTH, &dataH_RAW);
	MPUReadPort(TEMP_OUTL, &dataL_RAW);
	returnValue_RAW = (int16_t)(dataH_RAW << 8) | dataL_RAW;

	*tempMeasure = (returnValue_RAW / 340.0) + 36.53;;
}

static float readGyroX(){
	int8_t dataH_RAW = 0, dataL_RAW = 0;
	int16_t returnValue_RAW = 0;
	float returnValue = 0;
	MPUReadPort(GYRO_XOUTH, &dataH_RAW);
	MPUReadPort(GYRO_XOUTL, &dataL_RAW);
	returnValue_RAW = (int16_t)(dataH_RAW << 8 ) | dataL_RAW;
	returnValue = returnValue_RAW / GYRO_SENSITIVITY[GYRO_RANGE];
	return returnValue;
}

static float readGyroY(){
	int8_t dataH_RAW = 0, dataL_RAW = 0;
	int16_t returnValue_RAW = 0;
	float returnValue = 0;
	MPUReadPort(GYRO_YOUTH, &dataH_RAW);
	MPUReadPort(GYRO_YOUTL, &dataL_RAW);
	returnValue_RAW = (int16_t)(dataH_RAW << 8 ) | dataL_RAW;
	returnValue = returnValue_RAW / GYRO_SENSITIVITY[GYRO_RANGE];
	return returnValue;
}

static float readGyroZ(){
	int8_t dataH_RAW = 0, dataL_RAW = 0;
	int16_t returnValue_RAW = 0;
	float returnValue = 0;
	MPUReadPort(GYRO_ZOUTH, &dataH_RAW);
	MPUReadPort(GYRO_ZOUTL, &dataL_RAW);
	returnValue_RAW = (int16_t)(dataH_RAW << 8 ) | dataL_RAW;
	returnValue = returnValue_RAW / GYRO_SENSITIVITY[GYRO_RANGE];
	return returnValue;
}

static float readAccelX(){
	int8_t dataH_RAW = 0, dataL_RAW = 0;
	int16_t returnValue_RAW = 0;
	float returnValue = 0;
	MPUReadPort(ACCEL_XOUTH, &dataH_RAW);
	MPUReadPort(ACCEL_XOUTL, &dataL_RAW);
	returnValue_RAW = (int16_t)(dataH_RAW << 8 ) | dataL_RAW;
	returnValue = returnValue_RAW / ACCEL_SENSITIVITY[ACCEL_RANGE];
	return returnValue;
}

static float readAccelY(){
	int8_t dataH_RAW = 0, dataL_RAW = 0;
	int16_t returnValue_RAW = 0;
	float returnValue = 0;
	MPUReadPort(ACCEL_YOUTH, &dataH_RAW);
	MPUReadPort(ACCEL_YOUTL, &dataL_RAW);
	returnValue_RAW = (int16_t)(dataH_RAW << 8 ) | dataL_RAW;
	returnValue = returnValue_RAW / ACCEL_SENSITIVITY[ACCEL_RANGE];
	return returnValue;
}

static float readAccelZ(){
	int8_t dataH_RAW = 0, dataL_RAW = 0;
	int16_t returnValue_RAW = 0;
	float returnValue = 0;
	MPUReadPort(ACCEL_ZOUTH, &dataH_RAW);
	MPUReadPort(ACCEL_ZOUTL, &dataL_RAW);
	returnValue_RAW = (int16_t)(dataH_RAW << 8 ) | dataL_RAW;
	returnValue = returnValue_RAW / ACCEL_SENSITIVITY[ACCEL_RANGE];
	return returnValue;
}
#endif /* API_INC_API_UART_H_ */
