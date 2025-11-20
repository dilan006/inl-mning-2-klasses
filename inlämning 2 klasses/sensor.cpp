#include "sensor.h"
#include <random>

// Hjälpfunktion för att generera slumpmässiga värden
static double getRandomValue(double min, double max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(min, max);
    return dist(gen);
}

// TemperatureSensor implementation
TemperatureSensor::TemperatureSensor(double min, double max)
    : minValue(min), maxValue(max) {}

double TemperatureSensor::read() {
    return getRandomValue(minValue, maxValue);
}

std::string TemperatureSensor::getName() const {
    return "Temperature";
}

std::string TemperatureSensor::getUnit() const {
    return "°C";
}

// HumiditySensor implementation
HumiditySensor::HumiditySensor(double min, double max)
    : minValue(min), maxValue(max) {}

double HumiditySensor::read() {
    return getRandomValue(minValue, maxValue);
}

std::string HumiditySensor::getName() const {
    return "Humidity";
}

std::string HumiditySensor::getUnit() const {
    return "%";
}

// PressureSensor implementation
PressureSensor::PressureSensor(double min, double max)
    : minValue(min), maxValue(max) {}

double PressureSensor::read() {
    return getRandomValue(minValue, maxValue);
}

std::string PressureSensor::getName() const {
    return "Pressure";
}

std::string PressureSensor::getUnit() const {
    return "hPa";
}