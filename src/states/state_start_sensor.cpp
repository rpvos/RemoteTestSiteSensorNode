#include "states/state_start_sensor.hpp"

#include <Arduino.h>

StateStartSensor::StateStartSensor()
{
}

StateStartSensor::~StateStartSensor()
{
}

void StateStartSensor::PreFunction()
{
    Serial.println("Starting sensor");
}

void StateStartSensor::ExecuteFunction()
{
    Serial.print('.');
}

void StateStartSensor::PostFunction()
{
    Serial.println("\nSensor has started");
}
