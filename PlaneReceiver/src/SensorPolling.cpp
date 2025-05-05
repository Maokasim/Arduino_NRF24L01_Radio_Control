/**
 * THIS IS CODE FOR SENSOR POLLING
 * More settings and documentation you can find at "SensorPolling.h" file
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 */

#include "SensorPolling.h"

SensorPolling::SensorPolling() : m_gyro(Wire), m_VoltSensor()
{
    m_Angles[0] = 99;
    m_Angles[1] = 99;
    m_Voltage = 99;
}

void SensorPolling::mpu6050Setup()
{
    Wire.begin();
    m_gyro.begin();
    m_gyro.calcGyroOffsets(true);
}

void SensorPolling::ina219Setup()
{
    m_VoltSensor.begin();
}

int* SensorPolling::GetAngles()
{
    m_gyro.update();
    m_Angles[0] = m_gyro.getAngleX();
    m_Angles[1] = m_gyro.getAngleY();

    return m_Angles;
}

int SensorPolling::GetVoltage()
{
    m_Voltage = m_VoltSensor.getBusVoltage_V() * 10;

    return m_Voltage;
}