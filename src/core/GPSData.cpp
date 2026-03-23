#include "GPSData.h"

GPSData::GPSData(double latitude, double longitude,
    std::chrono::system_clock::time_point timestamp)
    : latitude(latitude), longitude(longitude),
    timestamp(timestamp) {
}

double GPSData::getLatitude() const {
    return latitude;
}

double GPSData::getLongitude() const {
    return longitude;
}

std::chrono::system_clock::time_point GPSData::getTimestamp() const {
    return timestamp;
}