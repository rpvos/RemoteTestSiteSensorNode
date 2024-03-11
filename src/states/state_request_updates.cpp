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
#ifdef DEBUG_PRINT
    Serial.println("Request updates");
#endif
}

void StateRequestUpdates::ExecuteFunction()
{
}

void StateRequestUpdates::PostFunction()
{
}
