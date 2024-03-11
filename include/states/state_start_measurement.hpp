#if !defined(STATE_START_MEASUREMENT_HPP_)
#define STATE_START_MEASUREMENT_HPP_

#include <a_state.hpp>
#include <succes_predicate.hpp>
#include <sensor_controller.hpp>

class StateStartMeasurement : public AState, public SuccesPredicate
{
private:
    SensorController *controller;

public:
    StateStartMeasurement(SensorController *controller = nullptr);
    ~StateStartMeasurement();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_START_MEASUREMENT_HPP_
