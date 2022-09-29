/**
 * @file main.cpp
 * @author Max T
 * @brief IT IS MAIN FILE OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (TRANSMITTER)
 * This file connects all separate files for different tasks, 
 * such as Transmitting data and receiving telemetry, Reading information from joysticks and Displaying information
 * @version 0.1
 * 
 */
#include <Arduino.h>
#include "NRF24Transmit.h"
#include "SensorRead.h"
#include "DisplayInfo.h"

void setup()
{
  Serial.begin(9600);
  RadioSetup();
  SensorSetup();
  DisplaySetup();
}

void loop()
{
  int Throttle = ThrottleCount();
  int *telemetry = RadioTransmit(Throttle, AileronCount(), ElevatorCount(), RudderCount());
  DisplayInformation(Throttle, *telemetry, *(telemetry + 1), *(telemetry + 2));
}
