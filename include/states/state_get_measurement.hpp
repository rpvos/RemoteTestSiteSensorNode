#if !defined(STATE_GET_MEASUREMENT_HPP_)
#define STATE_GET_MEASUREMENT_HPP_

#include <a_state.hpp>
#include <sensor_controller.hpp>
#include <succes_predicate.hpp>
#include "interfaces/i_add_measurements.hpp"

class StateGetMeasurement : public AState, public SuccesPredicate
{
private:
    SensorController *controller;
    IAddMeasurements *callback;

public:
    StateGetMeasurement(SensorController *controller = nullptr, IAddMeasurements *callback = nullptr);
    ~StateGetMeasurement();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_GET_MEASUREMENT_HPP_
