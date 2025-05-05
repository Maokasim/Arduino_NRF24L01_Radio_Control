/**
 * THIS IS CODE FOR RECEIVING INFORMATION
 * More settings and documentation you can find at .h file: "NRF24Transmit.h"
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 */

#include "NRF24Receiver.h"

NRF24Receiver::NRF24Receiver() : radio(9, 10)
{
  byte address[6][6] = {"1Node", "2Node", "3Node", "4Node", "5Node", "6Node"}; // possible pipe number
  memcpy(m_address, address, sizeof(address));
  m_error = 0;

  // m_received_data[4]; // Received data array
  // m_telemetry[3];     // Telemetry array
}

void NRF24Receiver::RadioSetup()
{
  radio.begin(); // Activate NRF24L01
  radio.setAutoAck(Receive_Confirmation_Mode);
  radio.setRetries(Time_Between_Transmit_Attempt, Number_Of_Transmit_Attempts);
  radio.enableAckPayload();                                        // Allow data transmit as answer on income signal
  radio.setPayloadSize(sizeof(m_received_data) + sizeof(m_telemetry)); // Package size (in bytes)
  radio.openReadingPipe(1, m_address[0]);                            // Set Reading pipe
  radio.setChannel(CH_NUM);                                        // Setting channel, chose one without noises
  radio.setPALevel(SIG_POWER);                                     // Transmitter power level
  radio.setDataRate(SIG_SPEED);                                    // setting transmit speed

  radio.powerUp();        // start working
  radio.startListening(); // Listen air, it is receiver
}

int* NRF24Receiver::RadioReceive(int Voltage, int Xangle, int Yangle)
{
  if (radio.available(&m_pipeNo))
  {
    radio.read(&m_received_data, sizeof(m_received_data));

    m_telemetry[0] = Voltage;
    m_telemetry[1] = Xangle;
    m_telemetry[2] = Yangle;

    radio.writeAckPayload(m_pipeNo, &m_telemetry, sizeof(m_telemetry)); // send telemetry
    data_ptr = m_received_data;
    m_error = 0;
  }
  else{
    m_error++;
  }
  if (m_error > 10) data_ptr = nullptr;

  return data_ptr;
}

bool NRF24Receiver::RadioConnected()
{
  m_RadioStatus = false;
  if (radio.available(&m_pipeNo)) m_RadioStatus = true;
  return m_RadioStatus;
}