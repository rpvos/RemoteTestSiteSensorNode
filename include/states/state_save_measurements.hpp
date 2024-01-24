#if !defined(STATE_SAVE_MEASUREMENTS_HPP_)
#define STATE_SAVE_MEASUREMENTS_HPP_

#include "a_state.hpp"

class StateSaveMeasurements : public AState
{
private:
public:
    StateSaveMeasurements();
    ~StateSaveMeasurements();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_SAVE_MEASUREMENTS_HPP_
