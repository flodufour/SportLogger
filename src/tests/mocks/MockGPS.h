#include <chrono>
#include "../../interfaces/IGPS.h"
#include "../../core/GPSData.h"

class MockGPS : public IGPS {
	double latitude = 37.7749f;  
	double longitude = -122.4194f;
	
public:
	GPSData readPosition(std::chrono::system_clock::time_point ts) override {
		latitude += 0.0001f;  
		longitude += 0.0001f; 
		return GPSData(latitude, longitude, ts);
	}
};