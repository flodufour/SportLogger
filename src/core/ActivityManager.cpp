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
    auto ts = std::chrono::system_clock::now();

    if (elevationSensor) {
        ElevationData e = elevationSensor->readElevation(ts);
        activity.addElevation(e);
    }

    if (heartRateSensor) {
        HeartRateData hr = heartRateSensor->readHeartRate(ts);
        activity.addHeartRate(hr);
    }

    if (gps) {
        GPSData g = gps->readPosition(ts);
        activity.addGPS(g);
    }
}

const Activity& ActivityManager::getActivity() const {
    return activity;
}