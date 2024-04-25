#if !defined(STATE_SEND_MEASUREMENTS_HPP_)
#define STATE_SEND_MEASUREMENTS_HPP_

#include <a_state.hpp>
#include <succes_predicate.hpp>
#include <connection_handler.hpp>
#include <interfaces/i_get_measurements.hpp>

class StateSendMeasurements : public AState, public SuccesPredicate
{
private:
    ConnectionHandler *connection_handler;
    IGetMeasurements *measurement_handler;

public:
    StateSendMeasurements(ConnectionHandler *handler, IGetMeasurements *measurement_handler);
    ~StateSendMeasurements();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_SEND_MEASUREMENTS_HPP_
