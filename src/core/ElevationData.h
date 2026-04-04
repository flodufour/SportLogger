#pragma once
#include <chrono>

/** 
* @class Elevationdata
* @brief Represents an elevation mesure and it's mesure time.
*/
class ElevationData {
public:
    /**
     * @brief Constructor of ElevationData.
     * @param elevationMeters Elevation in meters.
     * @param timestamp Timestamp corresponding to the mesure.
     */
    ElevationData(float elevationMeters, std::chrono::system_clock::time_point timestamp);

    // Getters
    float getElevation() const;
    std::chrono::system_clock::time_point getTimestamp() const;

private:
    float elevation; 
    std::chrono::system_clock::time_point timestamp;
};

