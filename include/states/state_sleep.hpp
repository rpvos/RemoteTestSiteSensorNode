#if !defined(STATE_SLEEP_HPP_)
#define STATE_SLEEP_HPP_

#include "a_state.hpp"

class StateSleep : public AState
{
private:
public:
    StateSleep();
    ~StateSleep();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_SLEEP_HPP_
