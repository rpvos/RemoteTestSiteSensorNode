#include "states/state_sleep.hpp"

#include <Arduino.h>

StateSleep::StateSleep()
{
}
StateSleep::~StateSleep()
{
}

void StateSleep::PreFunction()
{
    Serial.println("Sleep started");
}
void StateSleep::ExecuteFunction()
{
    Serial.print('.');
}
void StateSleep::PostFunction()
{
    Serial.println("\nSleep done");
}