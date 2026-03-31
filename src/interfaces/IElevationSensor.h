#pragma once
#include "../core/ElevationData.h"
#include <chrono>

/**
 * @brief Elevation sensor interface.
 */
class IElevationSensor {
public:
     /**
     * @brief Virtual destructor.
     */
    virtual ~IElevationSensor() = default;
    /**
    * @brief Gets the data from the elevation sensor
    * @params ts Timestamp of the data collection
    * @returns ElevationData Collected elevation data
    */
    virtual ElevationData readElevation(std::chrono::system_clock::time_point ts) = 0;
};
