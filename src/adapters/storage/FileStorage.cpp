#include "FileStorage.h"
#include <stdexcept>
#include <chrono>
#include <vector>

FileStorage::FileStorage(const std::string& fname)
    : filename(fname) {
}

void FileStorage::saveActivity(const Activity& activity) {
    std::ofstream file(filename, std::ios::out);
    if (!file.is_open())
        throw std::runtime_error("Cannot open file: " + filename);

    file << "timestamp_ms,elevation_m\n";

    const auto& elevations = activity.getElevations();

    for (const auto& e : elevations) {
        auto ts = std::chrono::duration_cast<std::chrono::milliseconds>(
            e.getTimestamp().time_since_epoch()).count();

        file << ts << "," << e.getElevation() << "\n";
    }

    file.close();
}