#if !defined(STATE_SEND_MEASUREMENTS_HPP_)
#define STATE_SEND_MEASUREMENTS_HPP_

#include "a_state.hpp"

class StateSendMeasurements : public AState
{
private:
public:
    StateSendMeasurements();
    ~StateSendMeasurements();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_SEND_MEASUREMENTS_HPP_
