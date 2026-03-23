#pragma once
#include "Activity.h"
#include "ElevationData.h"
#include "../interfaces/IElevationSensor.h"
#include "../interfaces/IStorage.h"
#include "../interfaces/IHeartRateSensor.h"
#include "../interfaces/IGPS.h"

class ActivityManager {
    Activity activity;
    IElevationSensor* elevationSensor;
	IHeartRateSensor* heartRateSensor;
	IGPS* gps;
    IStorage* storage;

public:
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

    void start();
    void stop();
    void collectData();

    const Activity& getActivity() const;
};