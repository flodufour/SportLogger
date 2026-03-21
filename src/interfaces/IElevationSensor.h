#pragma once
#include "../core/ElevationData.h"
#include <chrono>

class IElevationSensor {
public:
    virtual ~IElevationSensor() = default;
    virtual ElevationData readElevation(std::chrono::system_clock::time_point ts) = 0;

};