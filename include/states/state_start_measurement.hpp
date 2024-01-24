#if !defined(STATE_START_MEASUREMENT_HPP_)
#define STATE_START_MEASUREMENT_HPP_

#include "a_state.hpp"

class StateStartMeasurement : public AState
{
private:
public:
    StateStartMeasurement();
    ~StateStartMeasurement();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_START_MEASUREMENT_HPP_
