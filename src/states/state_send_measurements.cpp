#include "states/state_send_measurements.hpp"

StateSendMeasurements::StateSendMeasurements(ConnectionHandler *connection_handler, IGetMeasurements *measurement_handler)
{
    this->connection_handler = connection_handler;
    this->measurement_handler = measurement_handler;
}

StateSendMeasurements::~StateSendMeasurements()
{
    this->connection_handler = nullptr;
    this->measurement_handler = nullptr;
}

void StateSendMeasurements::PreFunction()
{
    Serial.println("Sending measurements");
}

void StateSendMeasurements::ExecuteFunction()
{
    if (connection_handler == nullptr && measurement_handler == nullptr)
    {
        return;
    }

    const size_t size = measurement_handler->GetAmountOfMeasurements();
    const RemoteTestSite_Measurement *measurements = measurement_handler->GetMeasurements();

    // Send measurements 1 by 1
    for (size_t i = 0; i < size; i++)
    {
        RemoteTestSite_Message message = RemoteTestSite_Message_init_zero;
        message.which_function_info = RemoteTestSite_Message_measurement_tag;

        message.function_info.measurement = measurements[i];
        bool succesfull_write = connection_handler->Write(message);
        if (!succesfull_write)
        {
            Serial.println("Measurement write was not succesfull");

            continue;
        }
        // TODO check for good time between messages
        delay(3000);

        // TODO: wait for acknowledge and maybe delay between messages
    }

    // TODO check if all meassages are sent correctly
    measurement_handler->ClearMeasurements();
    succes = true;
}

void StateSendMeasurements::PostFunction()
{
    succes = false;
}
