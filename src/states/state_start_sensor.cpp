#include "states/state_start_sensor.hpp"

#include <Arduino.h>

StateStartSensor::StateStartSensor(SensorController *controller)
{
    this->controller = controller;
}

StateStartSensor::~StateStartSensor()
{
    controller = nullptr;
}

void StateStartSensor::PreFunction()
{
#ifdef DEBUG_PRINT
    Serial.println("Starting sensor");
#endif
    if (controller != nullptr)
    {
        controller->EnableSensor();
    }
}

void StateStartSensor::ExecuteFunction()
{
#ifdef DEBUG_PRINT
    Serial.print('.');
#endif
}

void StateStartSensor::PostFunction()
{
#ifdef DEBUG_PRINT
    Serial.println("\nSensor has started");
#endif
}

unsigned long StateStartSensor::GetDurationInMs()
{
    if (controller != nullptr)
    {
        return controller->GetSensorStartupTime();
    }
    return 0;
}
