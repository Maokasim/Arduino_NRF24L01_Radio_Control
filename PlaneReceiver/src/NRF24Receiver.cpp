/**
 * THIS IS CODE FOR RECEIVING INFORMATION
 * More settings and documentation you can find at .h file: "NRF24Transmit.h"
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 */

#include "NRF24Receiver.h"

// -------------------- Variables --------------------

byte pipeNo;

byte address[][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; // possible pipe number

int received_data[4]; // Received data array
int telemetry[3];     // Telemetry array

// -------------------- Variables --------------------

RF24 radio(9, 10); // Create module for Arduino

void RadioSetup()
{
  radio.begin(); // Activate NRF24L01
  radio.setAutoAck(Receive_Confirmation_Mode);
  radio.setRetries(Time_Between_Transmit_Attempt, Number_Of_Transmit_Attempts);
  radio.enableAckPayload();                                        // Allow data transmit as answer on income signal
  radio.setPayloadSize(sizeof(received_data) + sizeof(telemetry)); // Package size (in bytes)
  radio.openReadingPipe(1, address[0]);                            // Set Reading pipe
  radio.setChannel(CH_NUM);                                        // Setting channel, chose one without noises
  radio.setPALevel(SIG_POWER);                                     // Transmitter power level
  radio.setDataRate(SIG_SPEED);                                    // setting transmit speed

  radio.powerUp();        // start working
  radio.startListening(); // Listen air, it is receiver
}

int *RadioReceive(int Voltage, int Xangle, int Yangle)
{
  if (radio.available(&pipeNo))
  {
    radio.read(&received_data, sizeof(received_data));

    telemetry[0] = Voltage;
    telemetry[1] = Xangle;
    telemetry[2] = Yangle;

    radio.writeAckPayload(pipeNo, &telemetry, sizeof(telemetry)); // send telemetry
  }

  return received_data;
}