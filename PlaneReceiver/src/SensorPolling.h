/**
 * THIS IS CODE FOR SENSOR POLLING
 *
 * This code reads information from sensor installed at RC model
 * In this case voltmeter ina219 module and gyroscope mpu6050 module
 * In this file you can find Libraries include and Function declaration.
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 */
#ifndef SENSORPOLLING_H
#define SENSORPOLLING_H

// -------------------- Libraries --------------------

#include <MPU6050_tockn.h>
#include <Adafruit_INA219.h>
#include <Wire.h>

// -------------------- Libraries --------------------

// -------------------- Functions --------------------

/// Setup and offset calibration for mpu 6050 gyroscope
void mpu6050Setup();

/// Setup for voltmeter ina219
void ina219Setup();

/**
 * @brief Function for getting x and y model angle angles
 *
 * @return Pointer to Angles data (x, y)
 */
int *GetAngles();

/**
 * @brief Function for getting battery level in volts
 *
 * @return Voltage value in int form. E.g. Battery voltage 12.4V, Func return int 124
 */
int GetVoltage();

// -------------------- Functions --------------------

#endif