#if !defined(I_ADD_MEASUREMENTS_HPP_)
#define I_ADD_MEASUREMENTS_HPP_

#include <stddef.h>
#include <proto/measurement.pb.h>

class IAddMeasurements
{
private:
public:
    virtual bool AddMeasurement(RemoteTestSite_Measurement measurement) = 0;
};

#endif // I_ADD_MEASUREMENTS_HPP_
