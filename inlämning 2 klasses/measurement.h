#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <string>

// Struktur för att lagra ett mätvärde
struct Measurement {
    std::string timestamp;
    std::string sensorName;
    double value;
    std::string unit;
};

#endif