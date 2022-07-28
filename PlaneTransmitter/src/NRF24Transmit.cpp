/**
 * THIS IS CODE FOR TRANSMITTING INFORMATION
 *
 * This code works on NRF24L01 module base.
 * Here it is two main function RadioSetup and RadioTransmit.
 * RadioSetup used to setup NRF24L01 module and set some settings (which you can change in this function).
 * RadioTransmit used for transmitting information and getting telemetry package.
 * More settings and documentation you can find at .h file: "NRF24Transmit.h"
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (TRANSMITTER)
 */

#include "NRF24Transmit.h"

// -------------------- Variables --------------------

byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; // possible pipe number

int transmit_data[4]; // Transmitted data array
int telemetry[3];     // Telemetry array

// -------------------- Variables --------------------

RF24 radio(9, 10); // Create module for Arduino

void RadioSetup()
{
  radio.begin(); // Activate NRF24L01
  radio.setAutoAck(Receive_Confirmation_Mode);
  radio.setRetries(Time_Between_Transmit_Attempt, Number_Of_Transmit_Attempts); 
  radio.enableAckPayload();                                        // Allow data transmit as answer on income signal
  radio.setPayloadSize(sizeof(transmit_data) + sizeof(telemetry)); // package size (in bytes)
  radio.openWritingPipe(address[0]);                               // Set NRF Node and open channel for transmitting
  radio.setChannel(CH_NUM);                                        // Setting channel, chose one without noises
  radio.setPALevel(SIG_POWER);                                     // Transmitter power level
  radio.setDataRate(SIG_SPEED);                                    // setting transmit speed

  radio.powerUp();       // start working
  radio.stopListening(); // do not listen air, it is transmitter
}

int *RadioTransmit(int Throttle, int Aileron, int Elevator, int Rudder)
{
  transmit_data[0] = Throttle;
  transmit_data[1] = Aileron;
  transmit_data[2] = Elevator;
  transmit_data[3] = Rudder;

  if (radio.write(&transmit_data, sizeof(transmit_data))) // send transmit_data package
  {
    while (radio.available()) // if it is something in answer
    {
      radio.read(&telemetry, sizeof(telemetry)); // read answer
      // get telemetry array from receiver
    }
  }
  return telemetry;
}