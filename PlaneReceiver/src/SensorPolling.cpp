/**
 * THIS IS CODE FOR SENSOR POLLING
 * More settings and documentation you can find at "SensorPolling.h" file
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 */

#include "SensorPolling.h"

//----------------- Objects -------------------

MPU6050 mpu6050(Wire);

Adafruit_INA219 ina219;

//----------------- Objects -------------------

// -------------------- Variables --------------------

int Angles[2];

int Voltage = 0;

// -------------------- Variables --------------------

void mpu6050Setup()
{
    Wire.begin();
    mpu6050.begin();
    mpu6050.calcGyroOffsets(true);
}

void ina219Setup()
{
    ina219.begin();
}

int *GetAngles()
{
    mpu6050.update();
    Angles[0] = mpu6050.getAngleX();
    Angles[1] = mpu6050.getAngleY();

    return Angles;
}

int GetVoltage()
{
    Voltage = ina219.getBusVoltage_V() * 10;

    return Voltage;
}