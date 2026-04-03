#pragma once
#include <string>
#include <chrono>
#include <vector>
#include "ElevationData.h"
#include "HeartRateData.h"
#include "GPSData.h"

/** 
* @brief Manages the life cycle of an activity. Handles the collection of the data from the sensors
*/
class Activity {
public:

	/** 
	* @brief Builds a new activity.
	* @param name Name of the activity.
	*/
    Activity(const std::string& name);

	/** 
	* @brief Starts the activity.
	*/
    void start(); 

	/** 
	* @brief Stops the activity.
	*/
    void stop();   

	/** 
	* @brief Adds an ElevationData to the activity.
	* @param elevation Elevation data.
	*/
    void addElevation(const ElevationData& elevation);

	/** 
	* @brief Adds an HeartRateData to the activity.
	* @param data HeartRateData data.
	*/
    void addHeartRate(const HeartRateData& data);

	/** 
	* @brief Adds a GPSData to the activity.
	* @param data GPSData data.
	*/
	void addGPS(const GPSData& data);

	// Getters
    std::string getName() const;
    std::chrono::system_clock::time_point getStartTime() const;
    std::chrono::system_clock::time_point getEndTime() const;
    std::chrono::seconds getDuration() const;
    const std::vector<ElevationData>& getElevations() const;
    const std::vector<HeartRateData>& getHeartRates() const;
    const std::vector<GPSData>& getGPS() const;

private:
    std::string name;
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point endTime;
    bool running = false; // Internal state
    std::vector<ElevationData> elevations;
	std::vector<HeartRateData> heartRates;
	std::vector<GPSData> gps;

};
