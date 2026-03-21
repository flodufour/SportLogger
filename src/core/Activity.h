#pragma once
#include <string>
#include <chrono>
#include <vector>
#include "ElevationData.h"

class Activity {
public:
    Activity(const std::string& name);

    void start();  
    void stop();   

    void addElevation(const ElevationData& elevation);

    std::string getName() const;
    std::chrono::system_clock::time_point getStartTime() const;
    std::chrono::system_clock::time_point getEndTime() const;
    std::chrono::seconds getDuration() const;
    const std::vector<ElevationData>& getElevations() const;


private:
    std::string name;
    std::chrono::system_clock::time_point startTime;
    std::chrono::system_clock::time_point endTime;
    bool running = false;
    std::vector<ElevationData> elevations;

};