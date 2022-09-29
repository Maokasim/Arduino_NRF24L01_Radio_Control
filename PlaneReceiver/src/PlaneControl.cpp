/**
 * THIS IS CODE FOR PLANE CONTROL
 * More settings and documentation you can find at "PlaneControl.h" file
 *
 * IT IS PART OF ARDUINO + NRF24L01 RADIO CONTROL PROJECT (RECEIVER)
 */

#include "PlaneControl.h"

// -------------------- Objects --------------------

Servo Motor;
Servo AileronServoLeft;
Servo AileronServoRight;
Servo ElevatorServo;
Servo RudderServo;

// -------------------- Objects --------------------

// -------------------- Variables --------------------

int Throttle = 0;
int Aileron = 512;
int Elevator = 512;
int Rudder = 512;

int ThrottleForMotor = 0;

int LeftAileronServoAngle = 90;
int RightAileronServoAngle = 90;
int ElevatorServoAngle = 90;
int RudderServoAngle = 90;

// -------------------- Variables --------------------

void ControlSetup()
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

void SetThrottle(int Throttle)
{
    ThrottleForMotor = map(Throttle, 0, 100, 800, 2299);
    Motor.writeMicroseconds(ThrottleForMotor);
}

void SetAilerons(int Aileron = 512)
{

    if (Aileron <= 512 - AileronDeadZone || Aileron >= 512 + AileronDeadZone)
    {
        LeftAileronServoAngle = map(Aileron, 0, 1023, 155, 25);
        RightAileronServoAngle = map(Aileron, 0, 1023, 155, 25);
    }

    if (Aileron >= 512 - AileronDeadZone && Aileron <= 512 + AileronDeadZone)
    {
        LeftAileronServoAngle = AileronNormalAngle;
        RightAileronServoAngle = AileronNormalAngle;
    }

    AileronServoLeft.write(LeftAileronServoAngle);
    AileronServoRight.write(RightAileronServoAngle);
}

void SetElevator(int Elevator)
{
    if (Elevator <= 512 - ElevatorDeadZone || Elevator >= 512 + ElevatorDeadZone)
        ElevatorServoAngle = map(Elevator, 0, 1023, 160, 10);
    if (Elevator >= 512 - ElevatorDeadZone && Elevator <= 512 + ElevatorDeadZone)
        ElevatorServoAngle = ElevatorNormalAngle;

    ElevatorServo.write(ElevatorServoAngle);
}

void SetRudder(int Rudder)
{
    if (Rudder <= 512 - RudderDeadZone || Rudder >= 512 + RudderDeadZone)
        RudderServoAngle = map(Rudder, 0, 1023, 20, 160);
    if (Rudder >= 512 - RudderDeadZone && Rudder <= 512 + RudderDeadZone)
        RudderServoAngle = RudderNormalAngle;

    RudderServo.write(RudderServoAngle);
}