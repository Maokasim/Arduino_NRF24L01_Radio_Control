/**
 * @file main.cpp
 * @author Max T
 * @brief IT IS MAIN FILE OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 *
 * @version 0.2
 */

#include "Plane.h"

Plane MyPlane;

void setup()
{
  MyPlane.PlaneSetup();
}

void loop()
{
  MyPlane.PlaneLoop();
}
