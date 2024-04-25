#include "states/state_measuring.hpp"

StateMeasuring::StateMeasuring(SensorController *controller)
{
    this->amount_of_measurements = 0;
    this->controller = controller;

    this->is_done_measuring = false;
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

bool StateMeasuring::Predicate()
{
    return is_done_measuring;
}

void StateMeasuring::PreFunction()
{
    Serial.println("Check for all measurements");
}

void StateMeasuring::ExecuteFunction()
{
    // Set to done when next measurement is not now
    is_done_measuring = controller->TimeUntillNextMeasurement();
}

void StateMeasuring::PostFunction()
{
}