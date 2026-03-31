#pragma once
#include "../core/GpsData.h"
#include <chrono>

/**
* @brief GPS Sensor interface.
*/
class IGPS {
public:
    /** 
    * @brief Virtual destructor.
    */
    virtual ~IGPS() = default;
    /** 
    * @brief Gets GPS data from the sensor.
    * @param ts TimeStamp of the data collection.
    * @return GPSData Collected GPS data.
    */
    virtual GPSData readPosition(std::chrono::system_clock::time_point ts) = 0;
};
