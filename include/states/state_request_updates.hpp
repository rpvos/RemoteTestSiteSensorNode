#if !defined(STATE_REQUEST_UPDATES_HPP_)
#define STATE_REQUEST_UPDATES_HPP_

#include "a_state.hpp"

class StateRequestUpdates : public AState
{
private:
public:
    StateRequestUpdates();
    ~StateRequestUpdates();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_REQUEST_UPDATES_HPP_
