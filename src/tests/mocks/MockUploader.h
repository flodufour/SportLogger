#pragma once
#include "../../interfaces/IUploader.h"
#include <string>
#include <iostream>

class MockUploader : public IUploader {
public:
    bool uploadActivity(const std::string& filePath,
        const std::string& name,
        const std::string& description) override
    {
        std::cout << "[MockUploader] Simulating upload...\n";
        std::cout << "File: " << filePath << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Description: " << description << "\n";

        return true; 
    }
};