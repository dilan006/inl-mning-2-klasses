#ifndef SENSOR_H
#define SENSOR_H

#include <string>

// Abstrakt basklass för alla sensorer
class Sensor {
public:
    virtual ~Sensor() = default;
    virtual double read() = 0;
    virtual std::string getName() const = 0;
    virtual std::string getUnit() const = 0;
};

// Temperatursensor
class TemperatureSensor : public Sensor {
private:
    double minValue;
    double maxValue;

public:
    TemperatureSensor(double min = 15.0, double max = 30.0);
    double read() override;
    std::string getName() const override;
    std::string getUnit() const override;
};

// Fuktighetssensor
class HumiditySensor : public Sensor {
private:
    double minValue;
    double maxValue;

public:
    HumiditySensor(double min = 30.0, double max = 80.0);
    double read() override;
    std::string getName() const override;
    std::string getUnit() const override;
};

// Trycksensor
class PressureSensor : public Sensor {
private:
    double minValue;
    double maxValue;

public:
    PressureSensor(double min = 950.0, double max = 1050.0);
    double read() override;
    std::string getName() const override;
    std::string getUnit() const override;
};

#endif