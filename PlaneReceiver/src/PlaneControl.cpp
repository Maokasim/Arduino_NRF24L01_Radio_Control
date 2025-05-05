/**
 * THIS IS CODE FOR PLANE CONTROL
 * More settings and documentation you can find at "PlaneControl.h" file
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 */

#include "PlaneControl.h"

PlaneControl::PlaneControl() : Motor(), AileronServoLeft(), AileronServoRight(), ElevatorServo(), RudderServo()
{
    m_Throttle = 0;
    m_Aileron = 512;
    m_Elevator = 512;
    m_Rudder = 512;

    m_ThrottleForMotor = 0;

    m_LeftAileronServoAngle = 90;
    m_RightAileronServoAngle = 90;
    m_ElevatorServoAngle = 90;
    m_RudderServoAngle = 90;
}

void PlaneControl::ControlSetup()
{

    // -------------------- Setup for Servo --------------------

    AileronServoLeft.attach(AileronServoLeftPin);
    AileronServoRight.attach(AileronServoRightPin);
    ElevatorServo.attach(ElevatorServoPin);
    RudderServo.attach(RubberServoPin);

    // -------------------- Setup for Servo --------------------

    // -------------------- Setup for Motor --------------------

    Motor.attach(8);
    Motor.writeMicroseconds(2300);
    delay(2000);
    Motor.writeMicroseconds(800);
    delay(6000);

    // -------------------- Setup for Motor --------------------
}

void PlaneControl::SetThrottle(int Throttle)
{
    m_ThrottleForMotor = map(Throttle, 0, 100, 800, 2299);
    Motor.writeMicroseconds(m_ThrottleForMotor);
}

void PlaneControl::SetAilerons(int Aileron = 512)
{

    if (Aileron <= 512 - AileronDeadZone || Aileron >= 512 + AileronDeadZone)
    {
        m_LeftAileronServoAngle = map(Aileron, 0, 1023, 155, 25);
        m_RightAileronServoAngle = map(Aileron, 0, 1023, 155, 25);
    }

    if (Aileron >= 512 - AileronDeadZone && Aileron <= 512 + AileronDeadZone)
    {
        m_LeftAileronServoAngle = AileronNormalAngle;
        m_RightAileronServoAngle = AileronNormalAngle;
    }

    AileronServoLeft.write(m_LeftAileronServoAngle);
    AileronServoRight.write(m_RightAileronServoAngle);
}

void PlaneControl::SetElevator(int Elevator)
{
    if (Elevator <= 512 - ElevatorDeadZone || Elevator >= 512 + ElevatorDeadZone)
        m_ElevatorServoAngle = map(Elevator, 0, 1023, 160, 10);
    if (Elevator >= 512 - ElevatorDeadZone && Elevator <= 512 + ElevatorDeadZone)
        m_ElevatorServoAngle = ElevatorNormalAngle;

    ElevatorServo.write(m_ElevatorServoAngle);
}

void PlaneControl::SetRudder(int Rudder)
{
    if (Rudder <= 512 - RudderDeadZone || Rudder >= 512 + RudderDeadZone)
        m_RudderServoAngle = map(Rudder, 0, 1023, 20, 160);
    if (Rudder >= 512 - RudderDeadZone && Rudder <= 512 + RudderDeadZone)
        m_RudderServoAngle = RudderNormalAngle;

    RudderServo.write(m_RudderServoAngle);
}