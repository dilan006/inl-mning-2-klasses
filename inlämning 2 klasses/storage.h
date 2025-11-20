#ifndef STORAGE_H
#define STORAGE_H

#include "measurement.h"
#include <vector>
#include <string>

// Klass för att lagra och hantera mätvärden
class MeasurementStorage {
private:
    std::vector<Measurement> measurements;

public:
    void addMeasurement(const Measurement& m);
    void printAll() const;
    void printStatistics(const std::string& sensorName) const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
    size_t getCount() const;
};

#endif