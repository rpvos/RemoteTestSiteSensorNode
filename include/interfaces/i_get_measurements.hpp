#if !defined(I_GET_MEASUREMENTS_HPP_)
#define I_GET_MEASUREMENTS_HPP_

#include <stddef.h>
#include <proto/measurement.pb.h>

class IGetMeasurements
{
private:
public:
    virtual size_t GetAmountOfMeasurements() = 0;
    virtual RemoteTestSite_Measurement *GetMeasurements() = 0;
};

#endif // I_GET_MEASUREMENTS_HPP_
