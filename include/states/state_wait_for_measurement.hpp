#if !defined(STATE_WAIT_FOR_MEASUREMENT_HPP_)
#define STATE_WAIT_FOR_MEASUREMENT_HPP_

#include "a_state.hpp"

class StateWaitForMeasurement : public AState
{
private:
public:
    StateWaitForMeasurement();
    ~StateWaitForMeasurement();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_WAIT_FOR_MEASUREMENT_HPP_
