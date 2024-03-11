#if !defined(STATE_WAIT_FOR_MEASUREMENT_HPP_)
#define STATE_WAIT_FOR_MEASUREMENT_HPP_

#include <a_state.hpp>
#include <sensor_controller.hpp>
#include <succes_predicate.hpp>

class StateWaitForMeasurement : public AState, public SuccesPredicate
{
private:
    SensorController *controller;

public:
    StateWaitForMeasurement(SensorController *controller = nullptr);
    ~StateWaitForMeasurement();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_WAIT_FOR_MEASUREMENT_HPP_
