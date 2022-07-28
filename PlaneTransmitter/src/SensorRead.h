/**
 * THIS IS CODE FOR READING INFORMATION
 * FROM JOYSTICKS AND ANOTHER SENSORS WHICH BUILD IN TRANSMITTER
 *
 * Code uses simple arduino logic commands
 * Here you can found Libraries include, Pins define and Function declaration
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (TRANSMITTER)
 */

#ifndef SENSOR_READ_H
#define SENSOR_READ_H

#include "Arduino.h"

// -------------------- Pin define --------------------

#define Joy1Xpin A2
#define Joy1Ypin A3

#define Joy2Xpin A6
#define Joy2Ypin A7

#define Joy1ButtPin 3
#define Joy2ButtPin 2

#define BlueButtPin 4

//-------------------- Pin define --------------------

// -------------------- Timer --------------------

#define period1 120
#define period2 70

// -------------------- Timer --------------------

//-------------------- Functions --------------------

/// Function for setting up transmitter control components, for example buttons and joysticks
void SensorSetup();

/// Function for reading joystick information for throttle value 0 - 1023 (Pin for joystick sets at "SensorRead.h" file at Joy1Ypin define)
int ThrottleCount();

/// Function for reading joystick information for Aileron value 0 - 1023 (Pin for joystick sets at "SensorRead.h" file at Joy1Xpin define)
int AileronCount();

/// Function for reading joystick information for Elevator value 0 -1023 (Pin for joystick sets at "SensorRead.h" file at Joy2Ypin define)
int ElevatorCount();

/// Function for reading joystick information for Rudder value 0 - 1023 (Pin for joystick sets at "SensorRead.h" file at Joy2Xpin define)
int RudderCount();

//-------------------- Functions --------------------

#endif