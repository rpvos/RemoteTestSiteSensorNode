#if !defined(REMOTE_TEST_SITE_FSM_HPP_)
#define REMOTE_TEST_SITE_FSM_HPP_

#include <finite_state_machine.hpp>
// Include Sensors
#include <sensor_controller.hpp>
#include <sensors/sensor_therm200_adapter.hpp>
#include <sensors/sensor_vh400_adapter.hpp>
#include <sensors/sensor_murata_soil_sensor_adapter.hpp>
#include <Arduino.h>

#define SENSOR_THERM200_ENABLE_PIN 4
#define SENSOR_VH400_ENABLE_PIN 5
#define RS485_MURATA_SOIL_SENSOR_ENABLE_PIN 6
#define SENSOR_MURATA_SOIL_SENSOR_ENABLE_PIN 7

#define SENSOR_THERM200_ADC_PIN A0
#define SENSOR_VH400_ADC_PIN A1

#define SENSOR_VOLTAGE 3.0
#define SENSOR_ADC_RESOLUTION 10

// Include all states
#include <states/state_sleep.hpp>
#include <states/state_measuring.hpp>
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

// Include communication headers
#include <message_handlers/RemoteTestSiteSensorNode.hpp>
#include <comunication_devices/usr_lg206_p_adapter.hpp>
#include <proto_handlers/proto_handler.hpp>

bool temp_predicate();

class RemoteTestSiteFSM
{
private:
    RS485 rs485_2 = RS485(RS485_MURATA_SOIL_SENSOR_ENABLE_PIN, RS485_MURATA_SOIL_SENSOR_ENABLE_PIN, &Serial2);

    static const size_t kSensorAmount = 3;
    SensorVh400Adapter vh400 = SensorVh400Adapter(SENSOR_VH400_ENABLE_PIN, SENSOR_VH400_ADC_PIN, SENSOR_ADC_RESOLUTION, SENSOR_VOLTAGE);
    SensorTherm200Adapter therm200 = SensorTherm200Adapter(SENSOR_THERM200_ENABLE_PIN, SENSOR_THERM200_ADC_PIN, SENSOR_ADC_RESOLUTION, SENSOR_VOLTAGE);
    SensorMurataSoilSensorAdapter murata_soil_sensor = SensorMurataSoilSensorAdapter(&rs485_2, SENSOR_MURATA_SOIL_SENSOR_ENABLE_PIN);

    ISensorAdapter *sensors[kSensorAmount] = {&vh400, &therm200, &murata_soil_sensor};

    SensorController controller = SensorController(sensors, kSensorAmount);

    FiniteStateMachine fsm = FiniteStateMachine();

    RemoteTestSiteSensorNode message_handler = RemoteTestSiteSensorNode();
    UsrLg206PAdapter communication_device = UsrLg206PAdapter();
    ProtoHelper proto_helper = ProtoHelper();
    ProtoHandler proto_handler = ProtoHandler(&proto_helper);

    ConnectionHandler connection_handler = ConnectionHandler(&message_handler, &communication_device, &proto_handler);

    // All states
    StateSleep state_sleep = StateSleep(&controller);
    StateMeasuring state_measuring = StateMeasuring(&controller);
    StateStartSensor state_start_sensor = StateStartSensor(&controller);
    StateStartMeasurement state_start_measurement = StateStartMeasurement(&controller);
    StateWaitForMeasurement state_wait_for_measurement = StateWaitForMeasurement(&controller);
    StateGetMeasurement state_get_measurement = StateGetMeasurement(&controller, &state_measuring);
    StateProcessMeasurement state_process_measurement = StateProcessMeasurement();
    StateConnectToBasestation state_connect_to_basestation = StateConnectToBasestation(&connection_handler);
    StateRequestUpdates state_request_updates = StateRequestUpdates();
    StateImplementUpdates state_implement_updates = StateImplementUpdates();
    StateSendMeasurements state_send_measurements = StateSendMeasurements(&connection_handler, &state_measuring);
    StateSaveMeasurements state_save_measurements = StateSaveMeasurements();

    PredicateTransition predicate_transitions[11] = {
        // Sensors have measured
        PredicateTransition(&state_measuring, &state_connect_to_basestation, &state_measuring),
        // Sensors need measuring
        PredicateTransition(&state_measuring, &state_start_sensor, &temp_predicate),
        PredicateTransition(&state_start_measurement, &state_wait_for_measurement, &state_start_measurement),
        PredicateTransition(&state_wait_for_measurement, &state_get_measurement, &state_wait_for_measurement),
        PredicateTransition(&state_get_measurement, &state_process_measurement, &state_get_measurement),
        PredicateTransition(&state_process_measurement, &state_measuring, &temp_predicate),
        // Communication states
        PredicateTransition(&state_connect_to_basestation, &state_request_updates, &temp_predicate),
        PredicateTransition(&state_request_updates, &state_implement_updates, &temp_predicate),
        PredicateTransition(&state_implement_updates, &state_send_measurements, &temp_predicate),
        PredicateTransition(&state_send_measurements, &state_sleep, &temp_predicate),
        PredicateTransition(&state_save_measurements, &state_sleep, &temp_predicate),
    };
    const size_t number_predicate_transitions = sizeof(predicate_transitions) / sizeof(PredicateTransition);

    TimedTransition timed_transitions[3] = {
        // Time for new measurement
        TimedTransition(&state_sleep, &state_measuring, &state_sleep),
        // Sensor has woken up
        TimedTransition(&state_start_sensor, &state_start_measurement, &state_start_sensor),
        // Timeout connection
        TimedTransition(&state_connect_to_basestation, &state_save_measurements, 30000),
    };

    size_t number_timed_transitions = sizeof(timed_transitions) / sizeof(TimedTransition);

public:
    RemoteTestSiteFSM();
    ~RemoteTestSiteFSM();

    void Update();
};

#endif // REMOTE_TEST_SITE_FSM_HPP_
