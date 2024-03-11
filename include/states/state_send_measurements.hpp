#if !defined(STATE_SEND_MEASUREMENTS_HPP_)
#define STATE_SEND_MEASUREMENTS_HPP_

#include <a_state.hpp>
#include <succes_predicate.hpp>
#include <connection_handler.hpp>
#include <sensor_controller.hpp>

class StateSendMeasurements : public AState, public SuccesPredicate
{
private:
    ConnectionHandler *handler;
    SensorController *controller;

public:
    StateSendMeasurements(ConnectionHandler *handler, SensorController *controller);
    ~StateSendMeasurements();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_SEND_MEASUREMENTS_HPP_
