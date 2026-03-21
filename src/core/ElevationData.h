#pragma once
#include <chrono>

class ElevationData {
public:
    ElevationData(float elevationMeters, std::chrono::system_clock::time_point timestamp);

    float getElevation() const;
    std::chrono::system_clock::time_point getTimestamp() const;

private:
    float elevation; 
    std::chrono::system_clock::time_point timestamp;
};

