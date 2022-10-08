#ifndef EEPROM_UTILS_H
#define EEPROM_UTILS_H

#include <Arduino.h>
#include <EEPROM.h>
#include "MPU9250.h"


const uint8_t EEPROM_SIZE = 1 + sizeof(float) * 3 * 4;
extern MPU9250 mpu;

enum EEP_ADDR {
    EEP_CALIB_FLAG = 0x00,
    EEP_ACC_BIAS = 0x01,
    EEP_GYRO_BIAS = 0x0D,
    EEP_MAG_BIAS = 0x19,
    EEP_MAG_SCALE = 0x25
};

void writeByte(int address, byte value);

void writeFloat(int address, float value);

byte readByte(int address);

float readFloat(int address);

void clearCalibration();

bool isCalibrated();

void saveCalibration();

void loadCalibration();

void printCalibration();

void printBytes();

void setupEEPROM();

#endif