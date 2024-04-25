#include "states/state_request_updates.hpp"
#include <Arduino.h>

StateRequestUpdates::StateRequestUpdates()
{
}

StateRequestUpdates::~StateRequestUpdates()
{
}

void StateRequestUpdates::PreFunction()
{
    Serial.println("Request updates");
}

void StateRequestUpdates::ExecuteFunction()
{
}

void StateRequestUpdates::PostFunction()
{
}
