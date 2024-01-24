#if !defined(STATE_PROCESS_MEASUREMENT_HPP_)
#define STATE_PROCESS_MEASUREMENT_HPP_

#include "a_state.hpp"

class StateProcessMeasurement : public AState
{
private:
public:
    StateProcessMeasurement();
    ~StateProcessMeasurement();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_PROCESS_MEASUREMENT_HPP_
