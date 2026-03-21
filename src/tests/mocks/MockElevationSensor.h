#include "../../core/ElevationData.h"
#include "../../interfaces/IElevationSensor.h"
#include <chrono>

class MockElevationSensor : public IElevationSensor {
    float elevation = 100.0f;
public:
    ElevationData readElevation(std::chrono::system_clock::time_point ts) override {
        elevation += 0.5f;
        return ElevationData(elevation, ts);
    }
};