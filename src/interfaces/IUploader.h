#pragma once
#include <string>

/** 
* @brief Interface for an uploader.
*/
class IUploader {
public:
    /** 
    * @brief Virtual destructor.
    */
    virtual ~IUploader() = default;
    /** 
    * @brief Uploads an activity.
    * @param filePath File path of the uploaded file.
    * @param name Name of the uploaded file.
    * @param description Description of the uploaded file.
    * @return bool Confirmation of the opload of the file.
    */
    virtual bool uploadActivity(const std::string& filePath,
        const std::string& name,
        const std::string& description) = 0;
};
