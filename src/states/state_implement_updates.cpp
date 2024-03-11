#include "states/state_implement_updates.hpp"
#include <Arduino.h>

StateImplementUpdates::StateImplementUpdates()
{
}

StateImplementUpdates::~StateImplementUpdates()
{
}

void StateImplementUpdates::PreFunction()
{
#ifdef DEBUG_PRINT
    Serial.println("Implement updates");
#endif
}

void StateImplementUpdates::ExecuteFunction()
{
}

void StateImplementUpdates::PostFunction()
{
}
