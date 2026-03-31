#pragma once
#include "../core/HeartRateData.h"
#include <chrono>

/**
* @brief Interface for a heart sensor.
*/
class IHeartRateSensor {
public:
			/**
			* @brief Virtual destructor.
			*/
			virtual ~IHeartRateSensor() = default;
			/**
			* @brief Gets heart rate data from the sensor.
			* @param ts Timestamp of the data collection.
			* @return HeartRateData Collected heart rate data.
			*/
			virtual HeartRateData readHeartRate(std::chrono::system_clock::time_point ts) = 0;
};
