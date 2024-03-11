#if !defined(STATE_CONNECT_TO_BASESTATION_HPP_)
#define STATE_CONNECT_TO_BASESTATION_HPP_

#include "a_state.hpp"
#include "succes_predicate.hpp"
#include "connection_handler.hpp"

class StateConnectToBasestation : public AState, public SuccesPredicate
{
private:
    ConnectionHandler *connection_handler;

public:
    StateConnectToBasestation(ConnectionHandler *connection_handler);
    ~StateConnectToBasestation();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_CONNECT_TO_BASESTATION_HPP_
