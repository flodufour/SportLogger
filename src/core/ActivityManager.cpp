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

    ElevationData e = elevationSensor->readElevation();
    activity.addElevation(e);
}

const Activity& ActivityManager::getActivity() const {
    return activity;
}