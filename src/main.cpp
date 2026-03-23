#include "core/ActivityManager.h"
#include "tests/mocks/MockElevationSensor.h"
#include "tests/mocks/MockHeartRateSensor.h"
#include "adapters/storage/FileStorage.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    MockElevationSensor elevationSensor;
	MockHeartRateSensor heartRateSensor;
    FileStorage storage("elevation.csv");

    ActivityManager manager("Morning Run", &elevationSensor, &heartRateSensor, &storage);

    manager.start();

    auto startTime = std::chrono::system_clock::now();
    while (std::chrono::system_clock::now() - startTime < std::chrono::seconds(10)) {
        manager.collectData();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    manager.stop(); 

    const auto& elevations = manager.getActivity().getElevations();
    for (const auto& e : elevations) {
        std::cout << "Elevation: " << e.getElevation() << " m\n";
    }

    const auto& hearRates = manager.getActivity().getHeartRates();
    for (const auto& hr : hearRates) {
        std::cout << "HR: " << hr.getHeartRate() << " m\n";
        std::cout << "SO2: " << hr.getOxygenSaturation() << " m\n";
    }

    std::cout << "Run duration: "
        << manager.getActivity().getDuration().count()
        << " seconds\n";

    return 0;
}