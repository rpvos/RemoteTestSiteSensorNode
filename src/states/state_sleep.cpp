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
    Serial.println("Sleep started");
}
void StateSleep::ExecuteFunction()
{
#ifdef DEBUG_PRINT
    Serial.print('.');
#endif
}
void StateSleep::PostFunction()
{
    Serial.println("Sleep done");
}

unsigned long StateSleep::GetDurationInMs()
{
    if (controller != nullptr)
    {
        return this->controller->TimeUntillNextMeasurement();
    }

    return 0;
}