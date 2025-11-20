#ifndef THRESHOLD_H
#define THRESHOLD_H

#include "measurement.h"
#include <vector>
#include <string>

// Regel för tröskelgräns
struct ThresholdRule {
    std::string sensorName;
    double limit;
    bool isOverLimit; // true = larm om över, false = larm om under
};

// Larmhändelse
struct AlarmEvent {
    std::string timestamp;
    std::string sensorName;
    double value;
    std::string message;
};

// Klass för att hantera tröskellarm
class ThresholdSystem {
private:
    std::vector<ThresholdRule> rules;
    std::vector<AlarmEvent> alarms;

public:
    void addRule(const ThresholdRule& rule);
    void checkMeasurement(const Measurement& m);
    void printAlarms() const;
    size_t getAlarmCount() const;
};

#endif