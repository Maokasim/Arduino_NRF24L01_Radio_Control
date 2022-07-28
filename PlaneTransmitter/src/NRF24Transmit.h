/**
 * THIS IS CODE FOR TRANSMITTING INFORMATION
 *
 * This code works on NRF24L01 module base and RF24.h library.
 * It support data transmit and telemetry up to 32 bytes. Estimated max range:1 km.
 * In this file you can find: Settings, Libraries include and Function declaration
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (TRANSMITTER)
 */

#ifndef NRF24Transmit_H
#define NRF24Transmit_H

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

/**
 * EXCHANGE SPEED
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

// -------------------- Functions ---------------------

/// RadioSetup is function for NRF24L01 module setup it`s include some parameters which should be set any time module reboot
void RadioSetup();

/**
 *@brief RadioTransmit is function for information transmit, send each parameter in 0-1023 format 
 *@brief NRF24L01 and this code can handle much bigger amount of information but Receiver expect information in (0 - 1023) range
 *@param Throttle for throttle level
 *@param Aileron for aileron level
 *@param Elevator for elevator level
 *@param Rudder for rudder level
 *@return telemetry array
 */
int *RadioTransmit(int Throttle, int Aileron, int Elevator, int Rudder);

// -------------------- Functions ---------------------

#endif