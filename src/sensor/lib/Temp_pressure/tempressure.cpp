#include <temppressure.h>

void printSuccess(String str) {
    Serial.println(REF_MSG_FAIL_BMP + str);
}

void printFail(String str) {
    Serial.println(REF_MSG_FAIL_BMP + str);
}

void configureBMP (Adafruit_BMP280::sensor_mode opMode = Adafruit_BMP280::MODE_FORCED,                   
                   Adafruit_BMP280::sensor_sampling tempOversampling =  Adafruit_BMP280::SAMPLING_X2,    
                   Adafruit_BMP280::sensor_sampling pressOversampling =  Adafruit_BMP280::SAMPLING_X16,  
                   Adafruit_BMP280::sensor_filter filtering = Adafruit_BMP280::FILTER_X16,               
                   Adafruit_BMP280::standby_duration standByTime = Adafruit_BMP280::STANDBY_MS_500) {   
    
    bmp.setSampling(opMode, tempOversampling, pressOversampling, filtering, standByTime); 
}


bool initializeBMP() {
    if (!bmp.begin()) {
        printFail("Could not find a valid sensor");
        return 0;
    }
    else {
        printSuccess("Connection success!");
        configureBMP();
    }

}

void updateValuesBMP() {
    realTimeDataTP.temp = bmp.readTemperature();
    realTimeDataTP.press = bmp.readPressure();
    realTimeDataTP.altitude = bmp.readAltitude(STANDART_BARO_PRESSURE);
}

float getPress() {
    return realTimeDataTP.press;
}

float getTemp() {
    return realTimeDataTP.temp;
}

float getAlt() {
    return realTimeDataTP.altitude;
}