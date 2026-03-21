// adapters/storage/FileStorage.h
#pragma once
#include "../../interfaces/IStorage.h"
#include <string>
#include <fstream>

class FileStorage : public IStorage {
    std::string filename;

public:
    explicit FileStorage(const std::string& fname);

    void saveActivity(const Activity& activity) override;
};