/*
 * API_uart.h
 *
 *  Created on: Sep 21, 2022
 *      Author: Marco Scasserra
 */

#ifndef API_INC_API_MPU6050_H_
#define API_INC_API_MPU6050_H_

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "API_delay.h"
#include "stm32f4xx_hal.h"
#include "stm32f4xx_nucleo_144.h"

#define MAX_TIMEOUT_MS 	1000

#define MPU6050_ADDR 	0x68

#define SMPRT_DIV		0x19
#define GYRO_CONFIG		0X1B
#define ACCEL_CONFIG	0X1C

#define ACCEL_XOUTH 	0x3B
#define ACCEL_XOUTL 	0x3C
#define ACCEL_YOUTH 	0x3D
#define ACCEL_YOUTL 	0x3E
#define ACCEL_ZOUTH 	0x3F
#define ACCEL_ZOUTL 	0x40
#define TEMP_OUTH 		0x41
#define TEMP_OUTL 		0x42
#define GYRO_XOUTH 		0x43
#define GYRO_XOUTL 		0x44
#define GYRO_YOUTH 		0x45
#define GYRO_YOUTL 		0x46
#define GYRO_ZOUTH 		0x47
#define GYRO_ZOUTL 		0x48
#define PWR_MGMT_1		0x6B

#define GYRO_RANGE		0
#define ACCEL_RANGE		0
#define PWR_CONFIG		0
#define SMPRT_CONFIG	7
#define GYRO_SMPRT		0
#define ACCEL_SMPRT		0

typedef struct {
	float gyroX;
	float gyroY;
	float gyroZ;
} gyroValues_t;

typedef struct {
	float accelX;
	float accelY;
	float accelZ;
} accelValues_t;

/* Exported functions --------------------------------------------------------*/
bool_t MPU6050Init();

void readGyro(gyroValues_t *gyroMeasure);

void readAccel(accelValues_t *accelMeasure);

void readTemp(float *tempMeasure);
#endif /* API_INC_API_MPU6050_H_ */
