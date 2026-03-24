#include "StravaUploader.h"

#include <cstdio>
#include <array>
#include <thread>
#include <chrono>
#include <sstream>


StravaUploader::StravaUploader(const std::string& accessToken)
    : token(accessToken) {
}

bool StravaUploader::uploadActivity(const std::string& filePath,
    const std::string& name,
    const std::string& description)
{
    std::string response = uploadFile(filePath, name, description);
    if (response.empty())
        return false;

    std::string key = "\"id\":";
    size_t pos = response.find(key);
    if (pos == std::string::npos)
        return false;

    pos += key.length();
    size_t end = response.find(",", pos);
    std::string uploadId = response.substr(pos, end - pos);

    return pollUploadStatus(uploadId);
}


std::string StravaUploader::uploadFile(const std::string& filePath,
    const std::string& name,
    const std::string& description)
{
    std::string cmd = buildCurlCommand(filePath, name, description);

    std::array<char, 256> buffer;
    std::string result;

    FILE* pipe = _popen(cmd.c_str(), "r");
    if (!pipe)
        return "";

    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr)
        result += buffer.data();

    _pclose(pipe);

    return result;
}


std::string StravaUploader::buildCurlCommand(const std::string& filePath,
    const std::string& name,
    const std::string& description)
{
    std::ostringstream cmd;

    cmd << "curl -s -X POST https://www.strava.com/api/v3/uploads "
        << "-H \"Authorization: Bearer " << token << "\" "
        << "-F \"file=@" << filePath << "\" "
        << "-F \"data_type=tcx\" "
        << "-F \"name=" << name << "\" "
        << "-F \"description=" << description << "\"";

    return cmd.str();
}



bool StravaUploader::pollUploadStatus(const std::string& uploadId)
{
    std::ostringstream cmd;
    cmd << "curl -s -H \"Authorization: Bearer " << token
        << "\" https://www.strava.com/api/v3/uploads/" << uploadId;

    for (int attempt = 0; attempt < 15; ++attempt)
    {
        std::array<char, 256> buffer;
        std::string result;

        FILE* pipe = _popen(cmd.str().c_str(), "r");
        if (!pipe)
            return false;

        while (fgets(buffer.data(), buffer.size(), pipe) != nullptr)
            result += buffer.data();

        _pclose(pipe);

        if (result.find("\"status\":\"Your activity is ready.\"") != std::string::npos)
            return true;

        if (result.find("\"error\":") != std::string::npos)
            return false;

        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return false; 
}