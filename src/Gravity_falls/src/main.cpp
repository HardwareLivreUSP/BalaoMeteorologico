#include <Arduino.h>
#include <I2Cdev.h>
#include <MPU6050_6Axis_MotionApps20.h>
#include <Wire.h>

#define SENSOR_READ_PERIOD 100
#define LED_BLINK_PERIOD 300


#define READY_BEACON_PIN_LED 5

#define MPU_ADDRESS 0x68

#define MIN_G 1 // m/s

MPU6050 mpu(MPU_ADDRESS);

bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;    // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;  // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;   // count of all bytes currently in FIFO
uint8_t fifoBuffer[64];  // FIFO storage buffer

Quaternion q;         // [w, x, y, z] quaternion container
VectorInt16 aa;       // [x, y, z] accel sensor measurements
VectorInt16 aaReal;   // [x, y, z] gravity-free accel sensor measurements
VectorFloat gravity;  // [x, y, z] gravity vector

uint32_t timerLed, timerSensor;

bool ledState = HIGH;


void initializationLed() {
  pinMode(READY_BEACON_PIN_LED, OUTPUT);
} 

// Initialization of accelerometer
void startAccelerometer(MPU6050 &MpuObject) {
    uint8_t devStatus;
    do {
        MpuObject.initialize();
        Serial.println(MpuObject.testConnection()
                           ? F("MPU6050 connection successful")
                           : F("MPU6050 connection failed"));
        devStatus = MpuObject.dmpInitialize();
        MpuObject.setFullScaleGyroRange(3);
        MpuObject.setFullScaleAccelRange(3);
        MpuObject.setDLPFMode(3);
        // Sensor readings with offsets:   7       7       16377   -1      1 1
        // Your offsets:   -4498   807     735     101     -71     -11
        MpuObject.setXAccelOffset(-4498);
        MpuObject.setYAccelOffset(807);
        MpuObject.setZAccelOffset(735);
        MpuObject.setXGyroOffset(101);
        MpuObject.setYGyroOffset(-71);
        MpuObject.setZGyroOffset(-11);

        if (devStatus == 0) {
            MpuObject.setDMPEnabled(true);
        } else
            Serial.println("\nFault Accelerometer\n");
    } while (devStatus != 0);
    Serial.println("MPU6050 started");

}


bool freeFallDetection() {
  //Adicionar timeout para tempo de queda e abertura do apraquedas
  if(aaReal.getMagnitude() < MIN_G) {
    digitalWrite(READY_BEACON_PIN_LED, HIGH);
    return 1;
  }
  else return 0;
}

//Retorna se deve ou nao abrir o paraquedas
// 0 = nao abre
// 1 = abre 
// -1 = erro de bufferoverflow do sensor
// -2 = erro bem errado

int mpuGetAceleration (MPU6050 &MpuObject) {
    packetSize = mpu.dmpGetFIFOPacketSize();
    mpuIntStatus = mpu.getIntStatus();
    fifoCount = mpu.getFIFOCount();
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        mpu.resetFIFO();
        return -1;
    } 
    else if (mpuIntStatus & 0x02) {
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        mpu.dmpGetQuaternion(&q, fifoBuffer);
        mpu.dmpGetGravity(&gravity, &q);
        mpu.dmpGetAccel(&aa, fifoBuffer);
        return freeFallDetection();
    }
    else return -2;
}

void initializeTimers() {
  timerLed = timerSensor = millis();
}

void setup() {
    Serial.begin(115200);
    Wire.setClock(400000);
    Wire.begin();
    startAccelerometer(mpu);
    initializeTimers();
}

void loop() {
  if(millis() - timerSensor > SENSOR_READ_PERIOD) {
    timerSensor = millis();
    mpuGetAceleration(mpu);
  }
  if(millis() - timerLed > LED_BLINK_PERIOD) {
    ledState = !ledState;
    digitalWrite(READY_BEACON_PIN_LED, ledState);
  }

}