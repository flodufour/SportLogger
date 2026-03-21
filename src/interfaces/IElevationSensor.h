#pragma once
#include "../core/ElevationData.h"
#include <chrono>

class IElevationSensor {
public:
    virtual ~IElevationSensor() = default;
    virtual ElevationData readElevation() = 0;
};