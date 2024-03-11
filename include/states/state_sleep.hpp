#if !defined(STATE_SLEEP_HPP_)
#define STATE_SLEEP_HPP_

#include <a_state.hpp>
#include <sensor_controller.hpp>
#include <i_get_duration_in_ms.hpp>

class StateSleep : public AState, public IGetDurationInMs
{
private:
    SensorController *controller;

public:
    StateSleep(SensorController *controller = nullptr);
    ~StateSleep();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;

    unsigned long GetDurationInMs() override;
};

#endif // STATE_SLEEP_HPP_
