#include "Plane.h"

Plane::Plane() : sens_pol(), plane_ctrl(), radio()
{
    Voltage = 0;
}

void Plane::PlaneSetup()
{
    Serial.begin(9600);
    Serial.println((String(millis())+ " | " + "Setup started"));
    sens_pol.mpu6050Setup();
    Serial.println(("\n" + String(millis())+ " | " +"Gyro setup - ok"));
    radio.RadioSetup();
    plane_ctrl.ControlSetup();
    sens_pol.ina219Setup();
    while(!radio.RadioConnected())
    {
        if(millis()%500 == 0)
        {
            Serial.println((String(millis())+ " | " +"waiting for radio to connect radio"));
        }
    }
    Serial.println((String(millis())+ " | " +"Setup done, connected to radio"));
    
}

void Plane::PlaneLoop()
{

    Voltage = sens_pol.GetVoltage();
    Angles = sens_pol.GetAngles();
    if(abs(*Angles) >= critical_angle ||  abs(*Angles + 1) >= critical_angle)
    {
        Serial.println((String(millis())+ " | " +"Attention Critical angle"));
    }
    ReceivedData = radio.RadioReceive(Voltage, *Angles, *(Angles + 1));
    if(ReceivedData == nullptr)
    {
        if(millis()%500 == 0)
        {
            Serial.println((String(millis())+ " | " +"FATAL ERROR NO RADIO SIGNAL"));
        }
        plane_ctrl.SetThrottle(0);
        plane_ctrl.SetAilerons(512);
        plane_ctrl.SetElevator(512);
        plane_ctrl.SetRudder(512);
    }else{
        plane_ctrl.SetThrottle(*ReceivedData);
        plane_ctrl.SetAilerons(*(ReceivedData + 1));
        plane_ctrl.SetElevator(*(ReceivedData + 2));
        plane_ctrl.SetRudder(*(ReceivedData + 3));
    }
}