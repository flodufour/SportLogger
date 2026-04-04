#pragma once
#include <string>
#include "Activity.h"

/**
 * @class TCXBuilder
 * @brief Responsible for exporting Activity data into the Garmin TCX (XML) format.
 */
class TCXBuilder {
public:
    /**
     * @brief Generates a TCX file from the provided Activity object.
     * @param activity The data source containing laps and trackpoints.
     * @param outputPath The full filesystem path where the .tcx file should be saved.
     * @return true if the file was written successfully, false otherwise.
     */
    bool build(const Activity& activity, const std::string& outputPath);

private:
    /**
     * @brief Converts a time_point to the ISO 8601 string format required by TCX.
     */
    std::string formatTimeISO8601(std::chrono::system_clock::time_point tp);
};
