#include "states/state_connect_to_basestation.hpp"
#include <Arduino.h>

StateConnectToBasestation::StateConnectToBasestation(ConnectionHandler *connection_handler)
{
    this->connection_handler = connection_handler;
}

StateConnectToBasestation::~StateConnectToBasestation()
{
}

void StateConnectToBasestation::PreFunction()
{
#ifdef DEBUG_PRINT
    Serial.println("Connecting to base station");
#endif
}

void StateConnectToBasestation::ExecuteFunction()
{
    if (connection_handler != nullptr)
    {
        // TODO: Remove
        //  succes = connection_handler->Connect(0);
        succes = true;
    }
}

void StateConnectToBasestation::PostFunction()
{
    succes = false;
}
