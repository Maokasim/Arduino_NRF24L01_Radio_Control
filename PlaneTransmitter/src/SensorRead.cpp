/**
 * THIS IS CODE FOR READING INFORMATION
 * FROM JOYSTICKS AND ANOTHER SENSORS WHICH BUILD IN TRANSMITTER
 *
 * Code include 1 void for setting up components (ComponentsSetup)
 * And 4 function for count each control channel (ThrottleCount, AileronCount, ElevatorCount, RudderCount)
 * Settings and detailed documentation you can find in "SensorRead.h" file
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (TRANSMITTER)
 */

// -------------------- Libraries --------------------

#include "SensorRead.h"

// -------------------- Libraries --------------------

// -------------------- Variables --------------------

int Throttle = 0;

int ThrottlePrep = 0; // pure value from joystick

float Voltage = 0;
float PrepVoltage = 96; // preparing value for Voltage

bool JoyButt1 = 0;

bool BlueButt = 0;
bool RedButt = 0;

// -------------------- Variables --------------------

// -------------------- Timer --------------------

uint32_t myTimer1;
uint32_t myTimer2;
uint32_t myTimer3;
uint32_t myTimer4;

// -------------------- Timer --------------------

//-------------------- Functions --------------------

void SensorSetup()
{

    //-------------------- set pinModes --------------------

    pinMode(Joy1ButtPin, INPUT);
    pinMode(BlueButtPin, INPUT);

    //-------------------- set pinModes --------------------
}

int ThrottleCount()
{
    /**
     * This code wrote for simple arduino joystick
     * And it is so complicated, because here I simulate special throttle joystick
     * (Which not come back to center after you touched the stick)
     * I understand that it is not best solution but it works (with standard cheep joystick)
     * and after I get special throttle joystick I will update code :)
     */
    // start of counting throttle
    ThrottlePrep = analogRead(Joy1Ypin);
    BlueButt = digitalRead(BlueButtPin);
    RedButt = digitalRead(RedButtPin);

    JoyButt1 = digitalRead(Joy1ButtPin);

    if (BlueButt == 1)
    {
        Throttle = 0;
    }

    if (RedButt == 1)
    {
        Throttle = 50;
    }

    if (ThrottlePrep >= 600 && Throttle < 100)
    {

        if (millis() - myTimer1 >= period1)
        {

            myTimer1 = millis();
            Throttle++;
        }
    }

    if (ThrottlePrep >= 600 && JoyButt1 == 0 && Throttle < 100)
    {
        if (millis() - myTimer2 >= period2)
        {
            myTimer2 = millis();
            Throttle++;
        }
    }
    // 2 cases when throttle increase first slow increase and second fast increase

    if (ThrottlePrep <= 400 && Throttle > 0)
    {
        if (millis() - myTimer3 >= period1)
        {
            myTimer3 = millis();
            Throttle--;
        }
    }

    if (ThrottlePrep <= 400 && JoyButt1 == 0 && Throttle > 0)
    {
        if (millis() - myTimer4 >= period2)
        {
            myTimer4 = millis();
            Throttle--;
        }
    }
    // 2 cases when throttle decrease first slow decrease and second fast decrease

    return Throttle;

    // End of Throttle counting
}

int AileronCount()
{
    // Ailerons counting
    int Aileron = analogRead(Joy1Xpin);

    return Aileron;
}

int ElevatorCount()
{
    // Elevator counting
    int Elevator = analogRead(Joy2Ypin);

    return Elevator;
}

int RudderCount()
{
    // Rudder counting
    int Rudder = analogRead(Joy2Xpin);

    return Rudder;
}

//-------------------- Functions --------------------