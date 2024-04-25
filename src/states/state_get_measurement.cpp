#include "states/state_get_measurement.hpp"

StateGetMeasurement::StateGetMeasurement(SensorController *controller, IAddMeasurements *callback)
{
    this->controller = controller;
    this->callback = callback;
}

StateGetMeasurement::~StateGetMeasurement()
{
    this->controller = nullptr;
}

void StateGetMeasurement::PreFunction()
{
    Serial.println("Getting measurements");
}

void StateGetMeasurement::ExecuteFunction()
{
    if (controller == nullptr || callback == nullptr)
    {
        return;
    }

    size_t amount = this->controller->GetMeasurementAmount();
    uint32_t measurements[amount];
    RemoteTestSite_MeasurementInfo types[amount];
    if (!this->controller->GetMeasurements(measurements))
    {
        return;
    }
    if (!this->controller->GetMeasurementTypes(types))
    {
        return;
    }

    for (size_t i = 0; i < amount; i++)
    {
        RemoteTestSite_Measurement measurement = RemoteTestSite_Measurement_init_zero;

        measurement.has_value = true;
        measurement.value = measurements[i];

        measurement.has_info = true;
        measurement.info = RemoteTestSite_MeasurementInfo(types[i]);

        succes = callback->AddMeasurement(measurement);

        if (!succes)
        {
            Serial.println("Not enough space in measurement buffer");
        }
    }

    // Update time when measurement is last done
    this->controller->UpdateTimeLastMeasurement();
    this->succes = true;
}

void StateGetMeasurement::PostFunction()
{
    this->controller->DisableSensor();
    this->succes = false;
}
