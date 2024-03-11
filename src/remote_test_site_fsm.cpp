#include "remote_test_site_fsm.hpp"
#include <Arduino.h>
#include <connection_handler.hpp>

RemoteTestSiteFSM::RemoteTestSiteFSM()
{
    pinMode(SENSOR_VH400_ENABLE_PIN, OUTPUT);
    pinMode(SENSOR_THERM200_ENABLE_PIN, OUTPUT);
    pinMode(SENSOR_VH400_ADC_PIN, INPUT);
    pinMode(SENSOR_THERM200_ADC_PIN, INPUT);

    controller.AddSensor(&vh400);
    controller.AddSensor(&therm200);

    controller.SetFrequency(MeasurementType::kMeasurementTypeTemperature, 60000);
    controller.SetFrequency(MeasurementType::kMeasurementTypeVwc, 60000);

    this->fsm = FiniteStateMachine(&state_sleep);

    fsm.SetPredicateTransitions(predicate_transitions, number_predicate_transitions);
    fsm.SetTimedTransitions(timed_transitions, number_timed_transitions);
}

RemoteTestSiteFSM::~RemoteTestSiteFSM()
{
}

void RemoteTestSiteFSM::Update()
{
    this->fsm.Update(millis());
}

bool temp_predicate()
{
    return true;
}
