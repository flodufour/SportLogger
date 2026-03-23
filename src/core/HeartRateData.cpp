#include "HeartRateData.h"

HeartRateData::HeartRateData(float heartRate,float oxygenSaturation, std::chrono::system_clock::time_point timestamp)
    : heartRate(heartRate), oxygenSaturation(oxygenSaturation), timestamp(timestamp) {
}

float HeartRateData::getOxygenSaturation() const {
    return oxygenSaturation;
}

float HeartRateData::getHeartRate() const {
    return heartRate;
}

std::chrono::system_clock::time_point HeartRateData::getTimestamp() const {
    return timestamp;
}