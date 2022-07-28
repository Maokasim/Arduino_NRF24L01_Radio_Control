/**
 * THIS IS CODE FOR DISPLAYING INFORMATION
 *
 * Code works with lcd I2C module and LiquidCrystal_I2C library
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (TRANSMITTER)
 */
#ifndef DISPLAY_INFO_H
#define DISPLAY_INFO_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//-------------- Display Settings ------------

#define THRpos 4 // Amount of letters on display for power + space(if it needed) = 3(THR) + 1 (Space) = 4
#define BATpos 4 // Amount of letters on display for power + space(if it needed) = 3(BAT) + 1(Space) = 4
#define Xpos 11  // -//-
#define Ypos 13  // -//-

//-------------- Display Settings ------------

//--------------- Functions ----------------

/// DisplaySetup is void for lcd display setup and displaying static components
void DisplaySetup();

/**
 * @brief DisplayInformation is void for displaying information on lcd
 * @param Throttle
 * @param Battery Battery charge level in volts, witch you should get from telemetry, by default: *telemetry
 * @param Xangle pitch angle, witch you should get from telemetry, by default: *(telemetry + 1)
 * @param Yangle yaw angle, witch you should get from telemetry, by default: *(telemetry + 2)
 */
void DisplayInformation(int Throttle, float Voltage, int Xangle, int Yangle);

//--------------- Functions ----------------

#endif