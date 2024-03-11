#if !defined(STATE_START_SENSOR_HPP_)
#define STATE_START_SENSOR_HPP_

#include <a_state.hpp>
#include <i_get_duration_in_ms.hpp>
#include <sensor_controller.hpp>

class StateStartSensor : public AState, public IGetDurationInMs
{
private:
    SensorController *controller;

public:
    StateStartSensor(SensorController *controller = nullptr);
    ~StateStartSensor();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;

    unsigned long GetDurationInMs() override;
};

#endif // STATE_START_SENSOR_HPP_
