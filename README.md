# SportLogger

SportLogger is a personal embedded systems project that records sports activities using a Raspberry Pi–based device.

The system collects heart rate, GPS, and elevation data during an activity, stores the session locally, and uploads it later to Strava when a network connection is available.

---

## System Overview

During an activity:

1. The heart rate sensor collects pulse data
2. The GPS module records position
3. The barometric sensor measures air pressure to estimate elevation
4. The system aggregates sensor data into an activity session
5. The session is stored locally on the device
6. When Wi-Fi is available, the activity is uploaded to Strava

---

## Hardware Platform

Target platform:

- Raspberry Pi Zero 2 W

External modules:

- MAX30102 heart rate sensor (I2C)
- NEO-6M GPS module (UART)
- USB power bank for portable power
- BME280 barometric pressure sensor (I2C) for elevation

---

## Software Architecture

The project follows a simplified clean architecture to keep the code organized and maintainable.

### Core Layer (`core/`)
Contains business logic independent from hardware:
- Activity data models
- Session management
- Data aggregation (heart rate, GPS, elevation)

### Interfaces Layer (`interfaces/`)
Defines abstract contracts for:
- Heart rate sensors
- GPS modules
- Elevation sensors
- Data storage
- Activity upload services

These interfaces allow hardware and services to be replaced without modifying core logic.

### Adapters Layer (`adapters/`)
Provides concrete implementations of the interfaces:
- Sensor communication
- GPS communication
- Barometric pressure sensor integration
- File-based storage
- Strava uploader

Adapters translate real-world data into usable domain objects.

### Drivers Layer (`drivers/`)
Handles low-level hardware communication:
- I2C communication
- UART communication
- Wi-Fi management
- File system access

This layer is platform-specific and isolated from business logic.

---

## Project Structure

<pre> ```SportLogger/
│
├─ CMakeLists.txt
├─ README.md
├─ LICENSE
│
├─ src/
│ ├─ main.cpp
│ │
│ ├─ core/
│ │ ├─ Activity.h               
│ │ ├─ Activity.cpp               
│ │ ├─ GPSData.h               
│ │ ├─ GPSData.cpp
│ │ ├─ HeartRateData.h               
│ │ ├─ HeartRateData.cpp               
│ │ ├─ ElevationData.h
│ │ ├─ ElevationData.cpp
│ │ ├─ ActivityManager.h
│ │ └─ ActivityManager.cpp
│ │
│ ├─ interfaces/
│ │ ├─ IHeartRateSensor.h                
│ │ ├─ IGPS.h               
│ │ ├─ IElevationSensor.h
│ │ ├─ IStorage.h
│ │ └─ IUploader.h
│ │
│ ├─ adapters/
│ │ ├─ sensors/
│ │ │ ├─ MAX30102Sensor.cpp              TODO
│ │ │ ├─ MAX30102Sensor.h              TODO
│ │ │ ├─ BME280Sensor.cpp              TODO
│ │ │ └─ BME280Sensor.h              TODO
│ │ │
│ │ ├─ gps/
│ │ │ ├─ NEO6MGPS.cpp              TODO
│ │ │ └─ NEO6MGPS.h              TODO
│ │ │
│ │ ├─ storage/
│ │ │ ├─ FileStorage.cpp
│ │ │ └─ FileStorage.h
│ │ │
│ │ └─ upload/
│ │ ├─ StravaUploader.cpp        TO TEST
│ │ └─ StravaUploader.h          TO TEST
│ │
│ └─ drivers/
│ ├─ I2CDriver.cpp               TODO
│ ├─ I2CDriver.h                 TODO
│ ├─ UARTDriver.cpp              TODO
│ ├─ UARTDriver.h                TODO
│ ├─ WiFiDriver.cpp              TODO
│ ├─ WiFiDriver.h                TODO
│
├─ third_party/
│ ├─ tinyxml2/
│ └─ json/
│
├─ tests/
│ ├─ ActivityManagerTests.cpp    TODO
│ └─ mocks/
│ ├─ MockHeartRateSensor.h          
│ ├─ MockGPS.h                   
│ ├─ MockElevationSensor.h       
│ ├─ MockStorage.h               
│ └─ MockUploader.h              
│
└─ docs/
└─ architecture.md               TODO```</pre>


## Sources

https://linux-dev.gitbook.io/communication-protocol-with-implementation/working-with-i2c-using-c++

https://developers.strava.com/docs/reference/

https://github.com/leethomason/tinyxml2
