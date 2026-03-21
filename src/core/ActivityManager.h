#pragma once
#include "Activity.h"
#include "ElevationData.h"
#include "../interfaces/IElevationSensor.h"
#include "../interfaces/IStorage.h"

class ActivityManager {
    Activity activity;
    IElevationSensor* elevationSensor;
    IStorage* storage;

public:
    ActivityManager(const std::string& name,
        IElevationSensor* elevSensor,
        IStorage* storagePtr)
        : activity(name),
        elevationSensor(elevSensor),
        storage(storagePtr) {
    }

    void start();
    void stop();
    void collectData();

    const Activity& getActivity() const;
};