#include "states/state_measuring.hpp"

StateMeasuring::StateMeasuring(SensorController *controller)
{
    this->amount_of_measurements = 0;
    this->measurements = nullptr;

    this->controller = controller;
}

StateMeasuring::~StateMeasuring()
{
    this->ClearMeasurements();
}

void StateMeasuring::AddMeasurement(RemoteTestSite_Measurement measurement)
{
    RemoteTestSite_Measurement *temp = new RemoteTestSite_Measurement[this->amount_of_measurements + 1];
    memcpy(temp, this->measurements, sizeof(RemoteTestSite_Measurement) * this->amount_of_measurements);

    temp[amount_of_measurements] = measurement;
    this->amount_of_measurements++;

    delete[] this->measurements;
    this->measurements = temp;
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
    delete[] this->measurements;
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