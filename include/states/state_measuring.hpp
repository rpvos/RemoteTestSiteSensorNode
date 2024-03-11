#if !defined(STATE_MEASURING_HPP_)
#define STATE_MEASURING_HPP_

#include <a_state.hpp>
#include <proto/measurement.pb.h>
#include "interfaces/i_get_measurements.hpp"
#include "interfaces/i_add_measurements.hpp"
#include "sensor_controller.hpp"
#include "succes_predicate.hpp"

class StateMeasuring : public AState, public SuccesPredicate, public IGetMeasurements, public IAddMeasurements
{
private:
    RemoteTestSite_Measurement *measurements;
    unsigned short amount_of_measurements;

    SensorController *controller;

public:
    StateMeasuring(SensorController *controller);
    ~StateMeasuring();

    void AddMeasurement(RemoteTestSite_Measurement measurement) override;
    size_t GetAmountOfMeasurements() override;
    RemoteTestSite_Measurement *GetMeasurements() override;
    void ClearMeasurements();

    void PreFunction() override;
    void ExecuteFunction() override;
    void PostFunction() override;
};

#endif // STATE_MEASURING_HPP_
