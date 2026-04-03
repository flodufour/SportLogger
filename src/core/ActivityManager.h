#pragma once
#include "Activity.h"
#include "ElevationData.h"
#include "../interfaces/IElevationSensor.h"
#include "../interfaces/IStorage.h"
#include "../interfaces/IHeartRateSensor.h"
#include "../interfaces/IGPS.h"

/**
 * @brief Manages data collection from all sensors into one Activity.
 */
class ActivityManager {
    Activity activity;
    IElevationSensor* elevationSensor;
	IHeartRateSensor* heartRateSensor;
	IGPS* gps;
    IStorage* storage;

public:
	/**
     * @brief Initialize the manager with its required sensors.
     * @param name The name for the new activity.
     * @param elevSensor Pointer to the elevation sensor.
     * @param hrSensor Pointer to the heart rate sensor.
     * @param gps Pointer to the GPS device.
     * @param storagePtr Pointer to the storage system.
     */
    ActivityManager(const std::string& name,
        IElevationSensor* elevSensor,
		IHeartRateSensor* hrSensor,
		IGPS* gps,    
        IStorage* storagePtr)
        : activity(name),
        elevationSensor(elevSensor),
		heartRateSensor(hrSensor),
		gps(gps),
        storage(storagePtr) {
    }

	/**
	* @brief Start the activity recording.
	*/
    void start();

	/**
	* @brief Stops the activity recording.
	*/
    void stop();

	/**
	* @brief Collect the data of the sensors into the activity.
	*/
    void collectData();

	// Getters
    const Activity& getActivity() const;
};
