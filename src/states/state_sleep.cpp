#include "states/state_sleep.hpp"

#include <Arduino.h>

StateSleep::StateSleep(SensorController *controller)
{
    this->controller = controller;
}
StateSleep::~StateSleep()
{
    this->controller = nullptr;
}

void StateSleep::PreFunction()
{
#ifdef DEBUG_PRINT
    Serial.println("Sleep started");
#endif
}
void StateSleep::ExecuteFunction()
{
#ifdef DEBUG_PRINT
    Serial.print('.');
#endif
}
void StateSleep::PostFunction()
{
#ifdef DEBUG_PRINT
    Serial.println("\nSleep done");
#endif
}

unsigned long StateSleep::GetDurationInMs()
{
    if (controller != nullptr)
    {
        return this->controller->TimeUntillNextMeasurement();
    }

    return 0;
}