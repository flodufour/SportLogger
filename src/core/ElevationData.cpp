#include "ElevationData.h"

ElevationData::ElevationData(float elevationMeters, std::chrono::system_clock::time_point timestamp)
    : elevation(elevationMeters), timestamp(timestamp) {
}

float ElevationData::getElevation() const {
    return elevation;
}

std::chrono::system_clock::time_point ElevationData::getTimestamp() const {
    return timestamp;
}