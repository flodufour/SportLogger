#pragma once
#include "../core/Activity.h"

class IStorage {
public:
    virtual ~IStorage() = default;
    virtual void saveActivity(const Activity& activity) = 0;
};