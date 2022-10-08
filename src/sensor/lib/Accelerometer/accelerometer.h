#ifndef _ACCELEROMETER_H
#define _ACCELEROMETER_H

#include <Arduino.h>
#include <MPU9250.h>
#include <eeprom_utils.h>

#define DEBUG_IMU 1

#define MPU9250_ADDR 0x68              //Sensor I2C array
#define EEPROM_BEG_ADDR 0x80           //EEPROM begin for ESP32


MPU9250Setting setting;

typedef struct _IMUdata {
    float accel[3];
    float gyro[3];
    float mag[3];
    float YawPitchRoll[3];
} IMUdata;

const String REF_MSG_SUCCESS_MPU = "[MPU9250] - ";
const String REF_MSG_FAIL_MPU =  "[!MPU9250!] - ";

IMUdata realTimeDataIMU;

/*Initialize the I2C bus and try to connect to MPU9250*/
bool initializeIMU();

/*Initialize routine of calibration of all IMU sensors*/
void calibrateIMU();

/*Setup the configuration for IMU*/
void configureMPU (ACCEL_FS_SEL accel_fs_sel,
                   GYRO_FS_SEL gyro_fs_sel,
                   MAG_OUTPUT_BITS mag_output_bits,
                   FIFO_SAMPLE_RATE fifo_sample_rate,
                   uint16_t gyro_fchoice,
                   GYRO_DLPF_CFG gyro_dlpf_cfg,
                   uint16_t accel_fchoice,
                   ACCEL_DLPF_CFG accel_dlpf_cfg);

/*RTOS thread like a funtion, parameter is the interval between the sample update)*/
 void updateValuesIMU(void *pvParameters);

/*return the last sampled values for yaw pitch roll in a float array*/
 float *getYawPitchRoll();

/*return the last sampled values for accel in a float array*/
 float *getAcc();

/*return the last sampled values for gyro in a float array*/
 float *getGyro();
 
 /*return the last sampled values for mag in a float array*/
 float *getMag();

#endif