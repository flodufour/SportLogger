#pragma once
#include "../core/GpsData.h"
#include <chrono>
class IGPS {
public:
    virtual ~IGPS() = default;
    virtual GPSData readPosition(std::chrono::system_clock::time_point ts) = 0;
};