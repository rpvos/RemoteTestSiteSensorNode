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
    if (handler != nullptr && controller != nullptr)
    {
        size_t size = controller->GetMeasurementAmount();
        uint32_t measurements[size];
        RemoteTestSite_MeasurementInfo measurement_types[size];
        if (controller->GetMeasurements(measurements) &&
            controller->GetMeasurementTypes(measurement_types))
        {

            // Repeat the write when it was not succesfull
            bool succesfull_write = false;
            for (size_t i = 0; i < size; i++)
            {
                RemoteTestSite_Message message = RemoteTestSite_Message_init_zero;
                message.which_function_info = RemoteTestSite_Message_measurement_tag;

                RemoteTestSite_Measurement measurement = RemoteTestSite_Measurement_init_zero;
                measurement.has_value = true;
                measurement.value = measurements[i];
                measurement.has_info = true;
                measurement.info = RemoteTestSite_MeasurementInfo((int)measurement_types[i]);

                message.function_info.measurement = measurement;
                succesfull_write = handler->Write(message);
                if (!succesfull_write)
                {
#ifdef PRINT_DEBUG
                    Serial.println("Measurement write was not succesfull");
#endif
                    continue;
                }

                // TODO: wait for acknowledge and maybe delay between messages
            }
        }
    }
    succes = true;
}

void StateSendMeasurements::PostFunction()
{
    succes = false;
}
