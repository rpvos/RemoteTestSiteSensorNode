#include "remote_test_site_fsm.hpp"
#include <Arduino.h>

bool temp_predicate(...)
{
    return true;
}

RemoteTestSiteFSM::RemoteTestSiteFSM()
{
    InitialiseStates();
    fsm = FiniteStateMachine(state_sleep);
    InitialiseTransitions();
}

RemoteTestSiteFSM::~RemoteTestSiteFSM()
{
}

void RemoteTestSiteFSM::Update()
{
    this->fsm.Update();
}

void RemoteTestSiteFSM::InitialiseStates()
{
    state_sleep = new StateSleep();
    state_start_sensor = new StateStartSensor();
    state_start_measurement = new StateStartMeasurement();
    state_wait_for_measurement = new StateWaitForMeasurement();
    state_get_measurement = new StateGetMeasurement();
    state_process_measurement = new StateProcessMeasurement();
    state_connect_to_basestation = new StateConnectToBasestation();
    state_request_updates = new StateRequestUpdates();
    state_implement_updates = new StateImplementUpdates();
    state_send_measurements = new StateSendMeasurements();
    state_save_measurements = new StateSaveMeasurements();
}

void RemoteTestSiteFSM::InitialiseTransitions()
{
    PredicateTransition predicate_transitions[] = {
        PredicateTransition(state_start_measurement, state_wait_for_measurement, temp_predicate),
        PredicateTransition(state_wait_for_measurement, state_get_measurement, temp_predicate),
        PredicateTransition(state_get_measurement, state_process_measurement, temp_predicate),
        PredicateTransition(state_process_measurement, state_connect_to_basestation, temp_predicate),
        PredicateTransition(state_connect_to_basestation, state_request_updates, temp_predicate),
        PredicateTransition(state_request_updates, state_implement_updates, temp_predicate),
        PredicateTransition(state_implement_updates, state_send_measurements, temp_predicate),
        PredicateTransition(state_send_measurements, state_sleep, temp_predicate),
        PredicateTransition(state_save_measurements, state_sleep, temp_predicate),
    };
    const size_t number_predicate_transitions = sizeof(predicate_transitions) / sizeof(PredicateTransition);

    fsm.SetPredicateTransitions(predicate_transitions, number_predicate_transitions);

    TimedTransition timed_transitions[] = {
        // Time for new measurement
        TimedTransition(state_sleep, state_start_sensor, 3000),
        // Sensor has woken up
        TimedTransition(state_start_sensor, state_start_measurement, 1000),
        // Timeout connection
        TimedTransition(state_connect_to_basestation, state_save_measurements, 10000),
    };

    size_t number_timed_transitions = sizeof(timed_transitions) / sizeof(TimedTransition);

    // Serial.println((unsigned int)timed_transitions[0].past_state, HEX);
    // Serial.println((unsigned int)timed_transitions[1].past_state, HEX);
    // Serial.println((unsigned int)timed_transitions[2].past_state, HEX);

    fsm.SetTimedTransitions(timed_transitions, number_timed_transitions);
}
