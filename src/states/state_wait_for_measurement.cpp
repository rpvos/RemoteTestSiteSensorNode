#include "states/state_wait_for_measurement.hpp"

StateWaitForMeasurement::StateWaitForMeasurement(SensorController *controller)
{
    this->controller = controller;
    this->succes = false;
}

StateWaitForMeasurement::~StateWaitForMeasurement()
{
    controller = nullptr;
}

void StateWaitForMeasurement::PreFunction()
{
}

void StateWaitForMeasurement::ExecuteFunction()
{
    if (this->controller != nullptr)
    {
        this->succes = controller->IsMeasurementFinnished();
    }
}

void StateWaitForMeasurement::PostFunction()
{
    succes = false;
}