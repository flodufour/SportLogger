#pragma once
#include "../../interfaces/IUploader.h"
#include <string>

class StravaUploader : public IUploader {
public:
    StravaUploader(const std::string& accessToken);

    bool uploadActivity(const std::string& filePath,
        const std::string& name,
        const std::string& description) override;

private:
    std::string token;

    std::string uploadFile(const std::string& filePath,
        const std::string& name,
        const std::string& description);

    bool pollUploadStatus(const std::string& uploadId);

    std::string buildCurlCommand(const std::string& filePath,
        const std::string& name,
        const std::string& description);
};