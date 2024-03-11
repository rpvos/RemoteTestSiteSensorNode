#include "states/state_start_measurement.hpp"

StateStartMeasurement::StateStartMeasurement(SensorController *controller)
{
    this->controller = controller;
    this->succes = false;
}

StateStartMeasurement::~StateStartMeasurement()
{
    controller = nullptr;
}

void StateStartMeasurement::PreFunction()
{
}

void StateStartMeasurement::ExecuteFunction()
{
    if (this->controller != nullptr)
    {
        this->succes = controller->StartMeasurement();
    }
}

void StateStartMeasurement::PostFunction()
{
    succes = false;
}
