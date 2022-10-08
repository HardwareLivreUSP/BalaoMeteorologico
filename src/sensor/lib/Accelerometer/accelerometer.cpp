#include <accelerometer.h>


MPU9250 mpu;

void printSuccess(String str) {
    Serial.println(REF_MSG_FAIL + str);
}

void printFail(String str) {
    Serial.println(REF_MSG_FAIL + str);
}


void configureMPU(ACCEL_FS_SEL accel_fs_sel = ACCEL_FS_SEL::A16G,
                   GYRO_FS_SEL gyro_fs_sel = GYRO_FS_SEL::G2000DPS,
                   MAG_OUTPUT_BITS mag_output_bits = MAG_OUTPUT_BITS::M16BITS,
                   FIFO_SAMPLE_RATE fifo_sample_rate = FIFO_SAMPLE_RATE::SMPL_200HZ,
                   uint16_t gyro_fchoice = 0x03,
                   GYRO_DLPF_CFG gyro_dlpf_cfg = GYRO_DLPF_CFG::DLPF_41HZ,
                   uint16_t accel_fchoice = 0x01,
                   ACCEL_DLPF_CFG accel_dlpf_cfg = ACCEL_DLPF_CFG::DLPF_45HZ) {
    setting.accel_fs_sel = accel_fs_sel;
    setting.gyro_fs_sel = gyro_fs_sel;
    setting.mag_output_bits = mag_output_bits;
    setting.fifo_sample_rate = fifo_sample_rate;
    setting.gyro_fchoice = gyro_fchoice;
    setting.gyro_dlpf_cfg = gyro_dlpf_cfg;
    setting.accel_fchoice = accel_fchoice;
    setting.accel_dlpf_cfg = accel_dlpf_cfg;
}



bool initializeIMU() {
    #if defined(ESP_PLATFORM) || defined(ESP8266)
        EEPROM.begin(EEPROM_BEG_ADDR);
    #endif

    Wire.begin();
    if (!mpu.setup(MPU9250_ADDR, setting)) {  // change to your own address
            printFail(" Connection failed. Please check your connection I2C");
            return false;
    }
    else {
        printSuccess("connection success!");
        configureMPU();
        if(DEBUG) mpu.verbose(true);
        return true;
    }
}

void calibrateIMU() {
     
    clearCalibration();
    
    printSuccess("Accel Gyro calibration will start in 5 sec.");
    printSuccess("Please leave the device still on the flat plane.");
    vTaskDelay(5000);
    mpu.calibrateAccelGyro();

    printSuccess("Magnetometer calibration will start in 5 sec.");
    printSuccess("Please Wave device in a figure eight until done.");
    mpu.calibrateMag();
    printSuccess("Calibration Done!");

    printCalibration();
    printSuccess("Saving calibration to EEPROM");
    saveCalibration();         //save calibration to eeprom

    loadCalibration();         //load calibration from eeprom
}

void updateValuesIMU(void *pvParameters, int sampleInterval) {
    while(1) {
        if (mpu.update()) {
            realTimeData.YawPitchRoll[0] = mpu.getYaw();
            realTimeData.YawPitchRoll[1] = mpu.getPitch();
            realTimeData.YawPitchRoll[2] = mpu.getRoll();
            
            realTimeData.accel[0] = mpu.getAccX();
            realTimeData.accel[1] = mpu.getAccY();
            realTimeData.accel[2] = mpu.getAccZ();
            
            realTimeData.gyro[0] = mpu.getGyroX();
            realTimeData.gyro[1] = mpu.getGyroY();
            realTimeData.gyro[2] = mpu.getGyroZ();

            realTimeData.mag[0] = mpu.getMagX();
            realTimeData.mag[1] = mpu.getMagY();
            realTimeData.mag[2] = mpu.getMagZ();
            vTaskDelay(*((int*)pvParameters));
        }
    }
}

float *getYawPitchRoll() {
    return realTimeData.YawPitchRoll;
}

float *getAcc() {
    return realTimeData.accel;
}

float *getGyro() {
    return realTimeData.gyro;
}
float *getMag() {
    return realTimeData.mag;
}