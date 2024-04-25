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
    Serial.println("Connecting to base station");
    if (connection_handler == nullptr)
    {
        return;
    }

    while (!connection_handler->Begin())
    {
        Serial.println("Begin communication not succesfull");
        delay(1000);
    }
}

void StateConnectToBasestation::ExecuteFunction()
{
    if (connection_handler == nullptr)
    {
        return;
    }

    succes = connection_handler->Connect(0);
}

void StateConnectToBasestation::PostFunction()
{
    succes = false;
}
