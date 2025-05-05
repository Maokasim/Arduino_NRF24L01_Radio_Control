/**
 * THIS IS CODE FOR RECEIVING INFORMATION
 *
 * This code works on NRF24L01 module base and RF24.h library.
 * It support data receive and telemetry sending up to 32 bytes. Estimated max range:1 km.
 * In this file you can find: Settings, Libraries include and Function declaration
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 */

#ifndef NRF24Receive_H
#define NRF24Receive_H

// -------------------- Libraries --------------------

#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

// -------------------- Libraries --------------------

// -------------------- NRF24L01 Settings --------------------

// CHANNEL NUMBER should be the same at the transmitter
#define CH_NUM 0x60

// TRANSMITTER POWER LEVEL
// Options: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
#define SIG_POWER RF24_PA_MAX

/** EXCHANGE SPEED
 * Options: RF24_2MBPS, RF24_1MBPS, RF24_250KBPS
 * This option should be the same at transmitter and receiver
 * At the lowest speed: highest sensitivity and range
 * ATTENTION!!! enableAckPayload do not work at 250KBPS speed
 */
#define SIG_SPEED RF24_1MBPS

/// 1 ON / 0 OFF
#define Receive_Confirmation_Mode 1

/// How long to wait between each retry, in multiples of 250 us.
#define Time_Between_Transmit_Attempt 5

/// Number of transmit attempts before giving up
#define Number_Of_Transmit_Attempts 15

// -------------------- NRF24L01 Settings --------------------

class NRF24Receiver
{
    private:
        RF24 radio; // Create module for Arduino
        // -------------------- Variables --------------------
        byte m_pipeNo;
        byte m_address[6][6]; // possible pipe number

        int m_received_data[4]; // Received data array
        int m_telemetry[3];     // Telemetry array
        bool m_RadioStatus;
        int m_error;
        // -------------------- Variables --------------------


    public:
        NRF24Receiver();

        // -------------------- Functions ---------------------
        /// RadioSetup is function for NRF24L01 module setup it`s include some parameters which should be set any time module reboot
        void RadioSetup();

        /**
         * @brief RadioReceive is function for information receive
         *
         * @param Voltage Value for battery voltage level,
         * @param Xangle Value for X rotation angle
         * @param Yangle Value for Y rotation angle
         * @return Pointer to received data
         */
        int *RadioReceive(int Voltage, int Xangle, int Yangle);

        bool RadioConnected();
        // -------------------- Functions ---------------------
};

#endif