#pragma once
#include "../../core/ElevationData.h"
#include "../../interfaces/IElevationSensor.h"
#include <chrono>

class MockElevationSensor : public IElevationSensor {
    float elevation = 100.0f;
public:
    ElevationData readElevation() override {
        elevation += 0.5f;
        return ElevationData(elevation, std::chrono::system_clock::now());
    }
};