#if !defined(STATE_START_SENSOR_HPP_)
#define STATE_START_SENSOR_HPP_

#include "a_state.hpp"

class StateStartSensor : public AState
{
private:
public:
    StateStartSensor();
    ~StateStartSensor();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_START_SENSOR_HPP_
