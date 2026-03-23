#pragma once
#include <chrono>

class HeartRateData {
public: 
	HeartRateData(float heartRate, float oxygenSaturation, std::chrono::system_clock::time_point timestamp);
	
	float getOxygenSaturation() const;
	float getHeartRate() const;
	std::chrono::system_clock::time_point getTimestamp() const;

private:

	float heartRate; 
	float oxygenSaturation;
	std::chrono::system_clock::time_point timestamp;
};