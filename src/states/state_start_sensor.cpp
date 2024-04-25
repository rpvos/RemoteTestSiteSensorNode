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
    Serial.println("Starting sensor");

    if (controller != nullptr)
    {
        controller->EnableSensor();
    }
}

void StateStartSensor::ExecuteFunction()
{
}

void StateStartSensor::PostFunction()
{
}

unsigned long StateStartSensor::GetDurationInMs()
{
    if (controller != nullptr)
    {
        return controller->GetSensorStartupTime();
    }
    return 0;
}
