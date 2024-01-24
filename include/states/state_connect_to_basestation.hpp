#if !defined(STATE_CONNECT_TO_BASESTATION_HPP_)
#define STATE_CONNECT_TO_BASESTATION_HPP_

#include "a_state.hpp"

class StateConnectToBasestation : public AState
{
private:
public:
    StateConnectToBasestation();
    ~StateConnectToBasestation();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_CONNECT_TO_BASESTATION_HPP_
