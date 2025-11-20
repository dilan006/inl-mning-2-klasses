#include "storage.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

void MeasurementStorage::addMeasurement(const Measurement& m) {
    measurements.push_back(m);
}

void MeasurementStorage::printAll() const {
    if (measurements.empty()) {
        std::cout << "Inga mätvärden lagrade.\n";
        return;
    }

    std::cout << "\n=== Alla Mätvärden ===\n";
    for (const auto& m : measurements) {
        std::cout << m.timestamp << " | "
                  << m.sensorName << " | "
                  << std::fixed << std::setprecision(2) << m.value << " "
                  << m.unit << "\n";
    }
}

void MeasurementStorage::printStatistics(const std::string &sensorName) const {
    std::vector<double> values;

    for (const auto& m : measurements) {
        if (m.sensorName == sensorName) {
            values.push_back(m.value);
        }
    }

    if (values.empty()) {
        std::cout << "Inga mätvärden för sensor: " << sensorName << "\n";
        return;
    }

    double sum = 0.0;
    double minVal = values[0];
    double maxVal = values[0];

    for (double v : values) {
        sum += v;
        if (v < minVal) minVal = v;
        if (v > maxVal) maxVal = v;
    }

    double mean = sum / values.size();
    double variance = 0.0;
    for (double v : values) {
        variance += (v - mean) * (v - mean);
    }
    variance /= values.size();
    double stdDev = std::sqrt(variance);

    std::cout << "\n=== Statistik för " << sensorName << " ===\n";
    std::cout << "Antal: " << values.size() << "\n";
    std::cout << "Medelvärde: " << std::fixed << std::setprecision(2) << mean << "\n";
    std::cout << "Min: " << minVal << "\n";
    std::cout << "Max: " << maxVal << "\n";
    std::cout << "Standardavvikelse: " << stdDev << "\n";
}

void MeasurementStorage::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Kunde inte öppna fil för skrivning.\n";
        return;
    }

    for (const auto& m : measurements) {
        file << m.timestamp << ","
             << m.sensorName << ","
             << m.value << ","
             << m.unit << "\n";
    }

    file.close();
}

void MeasurementStorage::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Kunde inte öppna fil för läsning.\n";
        return;
    }

    measurements.clear();
    std::string timestamp, sensorName, valueStr, unit;

    while (std::getline(file, timestamp, ',') &&
           std::getline(file, sensorName, ',') &&
           std::getline(file, valueStr, ',') &&
           std::getline(file, unit)) {

        try {
            double value;
            value = std::stod(valueStr);
            measurements.push_back({timestamp, sensorName, value, unit});
        } catch (...) {
            continue;
        }
    }

    file.close();
}

size_t MeasurementStorage::getCount() const {
    return measurements.size();
}