#pragma once
#include <string>
#include <chrono>
#include <vector>
#include "ElevationData.h"
#include "HeartRateData.h"
#include "GPSData.h"

class Activity {
public:
    Activity(const std::string& name);

    void start();  
    void stop();   

    void addElevation(const ElevationData& elevation);
    void addHeartRate(const HeartRateData& data);
	void addGPS(const GPSData& data);

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
    bool running = false;
    std::vector<ElevationData> elevations;
	std::vector<HeartRateData> heartRates;
	std::vector<GPSData> gps;

};