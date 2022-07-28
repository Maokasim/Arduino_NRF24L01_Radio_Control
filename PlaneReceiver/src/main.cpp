/**
 * @file main.cpp
 * @author Max T
 * @brief IT IS MAIN FILE OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 * This file connects all separate files for different tasks,
 * such as Receiving data and sending telemetry, Control Plane and Polling sensors
 *
 * @version 0.1
 */

#include <Arduino.h>
#include "NRF24Receiver.h"
#include "PlaneControl.h"
#include "SensorPolling.h"

void setup()
{
  RadioSetup();
  ControlSetup();
  mpu6050Setup();
  ina219Setup();
}

void loop()
{
  int Voltage = GetVoltage();
  int *Angles = GetAngles();
  int *ReceivedData;

  ReceivedData = RadioReceive(Voltage, *Angles, *(Angles + 1));
  SetThrottle(*ReceivedData);
  SetAilerons(*(ReceivedData + 1));
  SetElevator(*(ReceivedData + 2));
  SetRudder(*(ReceivedData + 3));
}
