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
    if (!elevationSensor || !heartRateSensor) return;

    auto ts = std::chrono::system_clock::now();
    ElevationData e = elevationSensor->readElevation(ts);
	HeartRateData hr = heartRateSensor->readHeartRate(ts);
	GPSData g = gps->readPosition(ts);
    activity.addHeartRate(hr);
    activity.addElevation(e);
    activity.addGPS(g);
}

const Activity& ActivityManager::getActivity() const {
    return activity;
}