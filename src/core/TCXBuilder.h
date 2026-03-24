#pragma once
#include <string>
#include "Activity.h"

class TCXBuilder {
public:
    bool build(const Activity& activity, const std::string& outputPath);

private:
    std::string formatTimeISO8601(std::chrono::system_clock::time_point tp);
};