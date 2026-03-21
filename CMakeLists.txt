cmake_minimum_required(VERSION 3.10)
project(SportLogger)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    # Main
    src/main.cpp

    # Core
    src/core/Activity.cpp
    src/core/ElevationData.cpp
    src/core/ActivityManager.cpp

    # Adapters - Storage
    src/adapters/storage/FileStorage.cpp
)

add_executable(SportLogger ${SOURCES})

# Include directories
target_include_directories(SportLogger PRIVATE
    src/core
    src/interfaces
    src/adapters
    src/drivers
)