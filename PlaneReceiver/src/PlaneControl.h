/**
 * THIS IS CODE FOR PLANE CONTROL
 *
 * This code control plane`s control surfaces and motor RPM.
 * In this file you can find Settings, Libraries include, Pins define and Function declaration.
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 */

#ifndef PlaneControl_H
#define PlaneControl_H

// -------------------- Libraries --------------------

#include "Arduino.h"
#include <Servo.h>

// -------------------- Libraries --------------------

// ----------------- Pin Define -------------------

#define ESCpin 8

#define RubberServoPin 4
#define ElevatorServoPin 5
#define AileronServoLeftPin 3
#define AileronServoRightPin 2

// ----------------- Pin Define -------------------

// -------------------- Define Dead Zones --------------------

// In all this DeadZones set value which we want subtract from standard middle value (512)
// Example: DeadZone=100, so value would send to the servo until 412=(512-100) and lower, and from 612=(512+100) and higher

#define AileronDeadZone 100
#define ElevatorDeadZone 100
#define RudderDeadZone 100

// Set angle for servo, when value for it is in dead zone

#define AileronNormalAngle 90
#define ElevatorNormalAngle 84
#define RudderNormalAngle 84

// -------------------- Define --------------------

class PlaneControl
{
    private:

        // -------------------- Objects --------------------
        Servo Motor;
        Servo AileronServoLeft;
        Servo AileronServoRight;
        Servo ElevatorServo;
        Servo RudderServo;
        // -------------------- Objects --------------------

        // -------------------- Variables --------------------
        int m_Throttle;
        int m_Aileron;
        int m_Elevator;
        int m_Rudder;

        int m_ThrottleForMotor;

        int m_LeftAileronServoAngle;
        int m_RightAileronServoAngle;
        int m_ElevatorServoAngle;
        int m_RudderServoAngle;
        // -------------------- Variables --------------------


    public:
        PlaneControl();
        // -------------------- Functions --------------------

        /// Function for Servos and Motor setup
        void ControlSetup();

        /**
         * @brief Function for setting Motor RPM
         * @param Throttle Throttle value in 0 - 1023 format
         */
        void SetThrottle(int Throttle);

        /**
         * @brief Function for setting Ailerons angle
         *
         * @param Aileron Aileron angle in 0 - 1023 format
         */
        void SetAilerons(int Aileron);

        /**
         * @brief Function for setting Elevator angle
         *
         * @param Elevator Elevator angle in 0 - 1023 format
         */
        void SetElevator(int Elevator);

        /**
         * @brief Function for setting Rudder angle
         *
         * @param Rudder Rudder angle in 0 - 1023 format
         */
        void SetRudder(int Rudder);

        // -------------------- Functions --------------------


};


#endif