#include "states/state_send_measurements.hpp"

StateSendMeasurements::StateSendMeasurements(ConnectionHandler *handler, SensorController *controller)
{
    this->handler = handler;
    this->controller = controller;
}

StateSendMeasurements::~StateSendMeasurements()
{
    this->handler = nullptr;
    this->controller = nullptr;
}

void StateSendMeasurements::PreFunction()
{
#ifdef DEBUG_PRINT
    Serial.println("Sending measurements");
#endif
}

void StateSendMeasurements::ExecuteFunction()
{
    // if (handler != nullptr && controller != nullptr)
    // {
    //     size_t size = controller->GetMeasurementAmount();
    //     float measurements[size];
    //     MeasurementType measurement_types[size];
    //     if (controller->GetMeasurements(measurements) &&
    //         controller->GetMeasurementTypes(measurement_types))
    //     {

    //         for (size_t i = 0; i < size; i++)
    //         {
    //             RemoteTestSite_Message message = RemoteTestSite_Message_init_zero;
    //             message.which_function_info = RemoteTestSite_Message_measurement_tag;

    //             RemoteTestSite_Measurement measurement = RemoteTestSite_Measurement_init_zero;
    //             measurement.has_value = true;
    //             measurement.value = measurements[i];
    //             measurement.has_type = true;
    //             measurement.type = RemoteTestSite_MeasurementType((int)measurement_types[i]);

    //             message.function_info.measurement = measurement;
    //             handler->Write(message);
    //             // TODO: wait for acknowledge and maybe delay between messages
    //         }
    //     }
    // }
    succes = true;
}

void StateSendMeasurements::PostFunction()
{
    succes = false;
}
