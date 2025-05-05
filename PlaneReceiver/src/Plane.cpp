#include "Plane.h"

Plane::Plane() : sens_pol(), plane_ctrl(), radio()
{
    m_Voltage = 0;
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

    m_Voltage = sens_pol.GetVoltage();
    m_Angles_ptr = sens_pol.GetAngles();
    if(abs(*m_Angles_ptr) >= critical_angle ||  abs(*m_Angles_ptr + 1) >= critical_angle)
    {
        Serial.println((String(millis())+ " | " +"Attention Critical angle"));
    }
    m_ReceivedData_ptr = radio.RadioReceive(m_Voltage, *m_Angles_ptr, *(m_Angles_ptr + 1));
    plane_ctrl.SetThrottle(*m_ReceivedData_ptr);
    plane_ctrl.SetAilerons(*(m_ReceivedData_ptr + 1));
    plane_ctrl.SetElevator(*(m_ReceivedData_ptr + 2));
    plane_ctrl.SetRudder(*(m_ReceivedData_ptr + 3));

}