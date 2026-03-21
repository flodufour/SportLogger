#include "ActivityManager.h"

void ActivityManager::start() {
    activity.start();
}

void ActivityManager::stop() {
    activity.stop();
    if (storage)
        storage->saveActivity(activity);
}

void ActivityManager::collectData() {
    if (!elevationSensor) return;

    auto ts = std::chrono::system_clock::now();
    ElevationData e = elevationSensor->readElevation(ts);
    activity.addElevation(e);
}

const Activity& ActivityManager::getActivity() const {
    return activity;
}