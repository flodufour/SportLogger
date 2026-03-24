#pragma once
#include <string>

class IUploader {
public:
    virtual ~IUploader() = default;

    virtual bool uploadActivity(const std::string& filePath,
        const std::string& name,
        const std::string& description) = 0;
};