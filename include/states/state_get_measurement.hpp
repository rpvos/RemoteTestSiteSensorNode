#if !defined(STATE_GET_MEASUREMENT_HPP_)
#define STATE_GET_MEASUREMENT_HPP_

#include "a_state.hpp"

class StateGetMeasurement : public AState
{
private:
public:
    StateGetMeasurement();
    ~StateGetMeasurement();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_GET_MEASUREMENT_HPP_
