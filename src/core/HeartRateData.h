#pragma once
#include <chrono>
   
/** 
* @class HeartRateData
* @brief Represents heart Rate mesure and their mesure time.
*/
class HeartRateData {
public: 
	 /**
    * @brief Constructor of HeartRateData.
    * @param heartRate HeartRate in bpm.
    * @param oxygenSaturation OxygenSaturation in SPo2.
    * @param timestamp Timestamp corresponding to the mesure.
    */
	HeartRateData(float heartRate, float oxygenSaturation, std::chrono::system_clock::time_point timestamp);

	// Getters
	float getOxygenSaturation() const;
	float getHeartRate() const;
	std::chrono::system_clock::time_point getTimestamp() const;

private:

	float heartRate; 
	float oxygenSaturation;
	std::chrono::system_clock::time_point timestamp;
};
