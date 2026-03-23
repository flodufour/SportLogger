#pragma once
#include <chrono>

class GPSData {
public:
    GPSData(double latitude, double longitude,
        std::chrono::system_clock::time_point timestamp);

    double getLatitude() const;
    double getLongitude() const;
    std::chrono::system_clock::time_point getTimestamp() const;
    

private:
    double latitude;
    double longitude;
    std::chrono::system_clock::time_point timestamp;
};