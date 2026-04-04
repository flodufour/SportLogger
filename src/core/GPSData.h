#pragma once
#include <chrono>    

/** 
* @class GPSData
* @brief Represents coordinates mesure and their mesure time.
*/
class GPSData {
public:
    /**
    * @brief Constructor of GPSData.
    * @param latitude Latitude in degrees.
    * @param longitude Longitude in degrees.
    * @param timestamp Timestamp corresponding to the mesure.
    */
    GPSData(double latitude, double longitude,
        std::chrono::system_clock::time_point timestamp);

    // Getters
    double getLatitude() const;
    double getLongitude() const;
    std::chrono::system_clock::time_point getTimestamp() const;
    

private:
    double latitude;
    double longitude;
    std::chrono::system_clock::time_point timestamp;
};
