#ifndef _TEMPPRESSURE_H
#define _TEMPPRESSURE_H
#include <Arduino.h>
#include <Adafruit_BMP280.h>

const String REF_MSG_SUCCESS_BMP = "[BMP280] - ";
const String REF_MSG_FAIL_BMP =  "[!BMP280!] - ";

#define BMP280_ADDR 0x58                      //Sensor I2C array
#define STANDART_BARO_PRESSURE 1013.25        //Local native pressure

Adafruit_BMP280 bmp;

typedef struct _TPdata {
    float temp;
    float press;
    float altitude;
} TPdata;

TPdata realTimeDataTP;

/*Initialize the I2C bus and try to connect to BMP280*/
bool initializeTP();

/*Setup the configuration for BMP280*/
void configureBMP (Adafruit_BMP280::sensor_mode opMode,                   /* Operating Mode. */
                   Adafruit_BMP280::sensor_sampling tempOversampling,     /* Temp. oversampling */
                   Adafruit_BMP280::sensor_sampling pressOversampling,    /* Pressure oversampling */
                   Adafruit_BMP280::sensor_filter filtering,              /* Filtering. */
                   Adafruit_BMP280::standby_duration standByTime);        /* Standby time. */

/*RTOS thread like a funtion, parameter is the interval between the sample update)*/
 void updateValuesBMP(void *pvParameters);

/*return the last sampled value for temp in degrees Celcius*/
 float getTemp();

/*return the last sampled value for press in Pascal*/
 float getPress();
 
 /*return the last sampled value for altitude, in meters , based in pressure*/
 float getAltitude();

#endif