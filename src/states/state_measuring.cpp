#include "states/state_measuring.hpp"

StateMeasuring::StateMeasuring(SensorController *controller)
{
    this->amount_of_measurements = 0;

    this->controller = controller;
}

StateMeasuring::~StateMeasuring()
{
    this->ClearMeasurements();
}

bool StateMeasuring::AddMeasurement(RemoteTestSite_Measurement measurement)
{
    if (this->amount_of_measurements < MEASUREMENTS_BUFFER_SIZE)
    {
        measurements[amount_of_measurements] = measurement;
        this->amount_of_measurements++;
        return true;
    }
    return false;
}

size_t StateMeasuring::GetAmountOfMeasurements()
{
    return this->amount_of_measurements;
}

RemoteTestSite_Measurement *StateMeasuring::GetMeasurements()
{
    return this->measurements;
}

void StateMeasuring::ClearMeasurements()
{
    this->amount_of_measurements = 0;
}

void StateMeasuring::PreFunction()
{
#ifdef DEBUG_PRINT
    Serial.println("Start measurement");
#endif
}

void StateMeasuring::ExecuteFunction()
{
    succes = controller->StartMeasurement();
}

void StateMeasuring::PostFunction()
{
    succes = false;
}