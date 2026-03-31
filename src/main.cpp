#include "core/ActivityManager.h"
#include "tests/mocks/MockElevationSensor.h"
#include "tests/mocks/MockHeartRateSensor.h"
#include "tests/mocks/MockGPS.h"
#include "tests/mocks/MockUploader.h"
#include "adapters/storage/FileStorage.h"
#include "core/TCXBuilder.h"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    MockElevationSensor elevationSensor;
	MockHeartRateSensor heartRateSensor;
	MockGPS gpsSensor;
	MockUploader uploader;
    FileStorage storage("elevation.csv");

	// Set and start an activity
    ActivityManager manager("Morning Run", &elevationSensor, &heartRateSensor, &gpsSensor, &storage);

    manager.start();

    auto startTime = std::chrono::system_clock::now();
	// Collect from the activity while it's active
    while (std::chrono::system_clock::now() - startTime < std::chrono::seconds(10)) {
        manager.collectData();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    manager.stop(); 

	// Save the activity to a tcx file
    TCXBuilder tcxBuilder;
    std::string tcxFile = "activity.tcx";
    bool tcxOk = tcxBuilder.build(manager.getActivity(), tcxFile);

    if (tcxOk)
        std::cout << "TCX file generated: " << tcxFile << "\n";
    else {
        std::cerr << "Failed to generate TCX file!\n";
        return 1;
    }

	// Upldoad the activity to Strava !
    bool uploadOk = uploader.uploadActivity(tcxFile, manager.getActivity().getName(), "Test upload");

    if (uploadOk)
        std::cout << "Upload simulated successfully.\n";
    else
        std::cerr << "Upload failed.\n";

    return 0;
}
