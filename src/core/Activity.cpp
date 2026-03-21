#include "Activity.h"
#include "ElevationData.h"
#include <stdexcept>


Activity::Activity(const std::string& name) : name(name) {}

void Activity::start() {
    if (running) {
        throw std::runtime_error("Activity already started");
    }
    startTime = std::chrono::system_clock::now();
    running = true;
}

void Activity::stop() {
    if (!running) {
        throw std::runtime_error("Activity not started yet");
    }
    endTime = std::chrono::system_clock::now();
    running = false;
}

void Activity::addElevation(const ElevationData& data) {
    elevations.push_back(data);
}

std::string Activity::getName() const {
    return name;
}

std::chrono::system_clock::time_point Activity::getStartTime() const {
    return startTime;
}

std::chrono::system_clock::time_point Activity::getEndTime() const {
    return endTime;
}

std::chrono::seconds Activity::getDuration() const {
    if (running) {
        return std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now() - startTime
        );
    }
    return std::chrono::duration_cast<std::chrono::seconds>(endTime - startTime);
}

const std::vector<ElevationData>& Activity::getElevations() const {
    return elevations;
}