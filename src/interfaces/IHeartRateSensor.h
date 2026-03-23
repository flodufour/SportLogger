#pragma once
#include "../core/HeartRateData.h"
#include <chrono>

class IHeartRateSensor {
public:
			virtual ~IHeartRateSensor() = default;
			virtual HeartRateData readHeartRate(std::chrono::system_clock::time_point ts) = 0;
};