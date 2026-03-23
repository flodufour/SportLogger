#pragma once
#include "../../interfaces/IHeartRateSensor.h"
#include "../../core/HeartRateData.h"
#include <chrono>

class MockHeartRateSensor : public IHeartRateSensor {
    float heartRate = 70.0f;
    float oxygenSaturation = 98.0f;
public:
    HeartRateData readHeartRate(std::chrono::system_clock::time_point ts) override {
        heartRate += 0.5f;           
        oxygenSaturation -= 0.1f;    
        return HeartRateData(heartRate, oxygenSaturation, ts);
    }
};