#if !defined(REMOTE_TEST_SITE_FSM_HPP_)
#define REMOTE_TEST_SITE_FSM_HPP_

#include <finite_state_machine.hpp>
// Include all states
#include <states/state_sleep.hpp>
#include <states/state_start_sensor.hpp>
#include <states/state_start_measurement.hpp>
#include <states/state_wait_for_measurement.hpp>
#include <states/state_get_measurement.hpp>
#include <states/state_process_measurement.hpp>
#include <states/state_connect_to_basestation.hpp>
#include <states/state_request_updates.hpp>
#include <states/state_implement_updates.hpp>
#include <states/state_send_measurements.hpp>
#include <states/state_save_measurements.hpp>

class RemoteTestSiteFSM
{
private:
    FiniteStateMachine fsm;

    void InitialiseStates();

    // All states
    StateSleep *state_sleep;
    StateStartSensor *state_start_sensor;
    StateStartMeasurement *state_start_measurement;
    StateWaitForMeasurement *state_wait_for_measurement;
    StateGetMeasurement *state_get_measurement;
    StateProcessMeasurement *state_process_measurement;
    StateConnectToBasestation *state_connect_to_basestation;
    StateRequestUpdates *state_request_updates;
    StateImplementUpdates *state_implement_updates;
    StateSendMeasurements *state_send_measurements;
    StateSaveMeasurements *state_save_measurements;

    void InitialiseTransitions();

public:
    RemoteTestSiteFSM();
    ~RemoteTestSiteFSM();

    void Update();
};

#endif // REMOTE_TEST_SITE_FSM_HPP_
