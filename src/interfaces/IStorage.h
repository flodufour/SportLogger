#pragma once
#include "../core/Activity.h"

/** 
* @brief Interface for the storage.
*/
class IStorage {
public:
    /**
    * @brief Virtual destructor.
    */
    virtual ~IStorage() = default;
    /**
    * @brief Saves the actvity.
    * @param activity Activity to be Saved
    * @return void
    */
    virtual void saveActivity(const Activity& activity) = 0;
};
