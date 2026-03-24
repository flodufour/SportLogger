#include "TCXBuilder.h"
#include "../third_party/tinyxml2/tinyxml2.h"
#include <map>
#include <sstream>

using namespace tinyxml2;

bool TCXBuilder::build(const Activity& activity, const std::string& outputPath)
{
    XMLDocument doc;

    XMLElement* root = doc.NewElement("TrainingCenterDatabase");
    root->SetAttribute("xmlns", "http://www.garmin.com/xmlschemas/TrainingCenterDatabase/v2");
    doc.InsertFirstChild(root);

    XMLElement* activities = doc.NewElement("Activities");
    root->InsertEndChild(activities);

    XMLElement* act = doc.NewElement("Activity");
    act->SetAttribute("Sport", "Running");
    activities->InsertEndChild(act);

    XMLElement* id = doc.NewElement("Id");
    id->SetText(formatTimeISO8601(activity.getStartTime()).c_str());
    act->InsertEndChild(id);

    XMLElement* lap = doc.NewElement("Lap");
    lap->SetAttribute("StartTime", formatTimeISO8601(activity.getStartTime()).c_str());
    act->InsertEndChild(lap);

    XMLElement* track = doc.NewElement("Track");
    lap->InsertEndChild(track);

    struct MergedSample {
        bool hasGPS = false;
        bool hasEle = false;
        bool hasHR = false;

        double lat = 0;
        double lon = 0;
        double ele = 0;
        int hr = 0;
    };

    std::map<std::time_t, MergedSample> timeline;

    for (const auto& g : activity.getGPS()) {
        std::time_t t = std::chrono::system_clock::to_time_t(g.getTimestamp());
        timeline[t].hasGPS = true;
        timeline[t].lat = g.getLatitude();
        timeline[t].lon = g.getLongitude();
    }

    for (const auto& e : activity.getElevations()) {
        std::time_t t = std::chrono::system_clock::to_time_t(e.getTimestamp());
        timeline[t].hasEle = true;
        timeline[t].ele = e.getElevation();
    }

    for (const auto& h : activity.getHeartRates()) {
        std::time_t t = std::chrono::system_clock::to_time_t(h.getTimestamp());
        timeline[t].hasHR = true;
        timeline[t].hr = h.getHeartRate();
    }

    for (const auto& [t, sample] : timeline)
    {
        XMLElement* tp = doc.NewElement("Trackpoint");

        auto tpTime = std::chrono::system_clock::from_time_t(t);

        XMLElement* time = doc.NewElement("Time");
        time->SetText(formatTimeISO8601(tpTime).c_str());
        tp->InsertEndChild(time);

        if (sample.hasGPS) {
            XMLElement* pos = doc.NewElement("Position");

            XMLElement* lat = doc.NewElement("LatitudeDegrees");
            lat->SetText(sample.lat);
            pos->InsertEndChild(lat);

            XMLElement* lon = doc.NewElement("LongitudeDegrees");
            lon->SetText(sample.lon);
            pos->InsertEndChild(lon);

            tp->InsertEndChild(pos);
        }

        if (sample.hasEle) {
            XMLElement* ele = doc.NewElement("AltitudeMeters");
            ele->SetText(sample.ele);
            tp->InsertEndChild(ele);
        }

        if (sample.hasHR) {
            XMLElement* hr = doc.NewElement("HeartRateBpm");
            XMLElement* val = doc.NewElement("Value");
            val->SetText(sample.hr);
            hr->InsertEndChild(val);
            tp->InsertEndChild(hr);
        }

        track->InsertEndChild(tp);
    }

    return doc.SaveFile(outputPath.c_str()) == XML_SUCCESS;
}

std::string TCXBuilder::formatTimeISO8601(std::chrono::system_clock::time_point tp)
{
    std::time_t t = std::chrono::system_clock::to_time_t(tp);
    std::tm* gmt = std::gmtime(&t);

    char buffer[32];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%dT%H:%M:%SZ", gmt);
    return std::string(buffer);
}