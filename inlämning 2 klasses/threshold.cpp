#include "threshold.h"
#include <iostream>
#include <iomanip>

void ThresholdSystem::addRule(const ThresholdRule& rule) {
    rules.push_back(rule);
    std::cout << "Regel tillagd för " << rule.sensorName << "\n";
}

void ThresholdSystem::checkMeasurement(const Measurement& m) {
    for (const auto& rule : rules) {
        if (rule.sensorName != m.sensorName) {
            continue;
        }

        bool shouldAlarm = false;
        std::string message;

        if (rule.isOverLimit && m.value > rule.limit) {
            shouldAlarm = true;
            message = "Värde över gräns (" + std::to_string(rule.limit) + ")";
        } else if (!rule.isOverLimit && m.value < rule.limit) {
            shouldAlarm = true;
            message = "Värde under gräns (" + std::to_string(rule.limit) + ")";
        }

        if (shouldAlarm) {
            alarms.push_back({m.timestamp, m.sensorName, m.value, message});
        }
    }
}

void ThresholdSystem::printAlarms() const {
    if (alarms.empty()) {
        std::cout << "Inga larm registrerade.\n";
        return;
    }

    std::cout << "\n=== Larmhändelser ===\n";
    for (const auto& alarm : alarms) {
        std::cout << alarm.timestamp << " | "
                  << alarm.sensorName << " | "
                  << std::fixed << std::setprecision(2) << alarm.value << " | "
                  << alarm.message << "\n";
    }
}

size_t ThresholdSystem::getAlarmCount() const {
    return alarms.size();
}