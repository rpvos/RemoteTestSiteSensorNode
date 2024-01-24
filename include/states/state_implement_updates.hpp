#if !defined(STATE_IMPLEMENT_UPDATES_HPP_)
#define STATE_IMPLEMENT_UPDATES_HPP_

#include "a_state.hpp"

class StateImplementUpdates : public AState
{
private:
public:
    StateImplementUpdates();
    ~StateImplementUpdates();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_IMPLEMENT_UPDATES_HPP_
