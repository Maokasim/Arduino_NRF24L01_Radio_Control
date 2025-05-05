/*
* This Class connects all separate classes in composition.
* Resolving separate tasks, such as Receiving data and sending telemetry, Control Plane and Polling sensors
*/
#ifndef PLANE_H
#define PLANE_H

#include <Arduino.h>
#include "NRF24Receiver.h"
#include "PlaneControl.h"
#include "SensorPolling.h"

#define critical_angle 60

class Plane
{
    private:
        int Voltage;
        int *Angles;
        int *ReceivedData;

        SensorPolling sens_pol;
        PlaneControl plane_ctrl;
        NRF24Receiver radio;

    public:
        Plane();
        void PlaneSetup();
        void PlaneLoop();
};

#endif