#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include "sensor.h"
#include "measurement.h"
#include "storage.h"
#include "threshold.h"
#include "utils.h"

void printMenu() {
    std::cout << "\n========== SENSOR SYSTEM ==========\n";
    std::cout << "1. Läs av alla sensorer\n";
    std::cout << "2. Visa statistik för sensor\n";
    std::cout << "3. Visa alla mätvärden\n";
    std::cout << "4. Lägg till tröskelregel\n";
    std::cout << "5. Visa larm\n";
    std::cout << "6. Spara till fil\n";
    std::cout << "7. Ladda från fil\n";
    std::cout << "8. Avsluta\n";
    std::cout << "===================================\n";
    std::cout << "Välj (1-8): ";
}

auto readAllSensors(const std::vector<std::unique_ptr<Sensor> > &sensors,
                    MeasurementStorage &storage,
                    ThresholdSystem &thresholds) -> void {
    std::cout << "\n--- Läser av sensorer ---\n";

    for (auto& sensor : sensors) {
        double value = sensor->read();
        Measurement m{
            getCurrentTimestamp(),
            sensor->getName(),
            value,
            sensor->getUnit()
        };

        storage.addMeasurement(m);
        thresholds.checkMeasurement(m);

        std::cout << sensor->getName() << ": "
                  << value << " " << sensor->getUnit() << "\n";
    }
}

void showStatistics(const MeasurementStorage& storage) {
    std::cout << "\nAnge sensornamn (Temperature/Humidity/Pressure): ";
    std::string name;
    std::cin >> name;
    storage.printStatistics(name);
}

void addThresholdRule(ThresholdSystem& thresholds) {
    ThresholdRule rule;

    std::cout << "\nAnge sensornamn: ";
    std::cin >> rule.sensorName;

    std::cout << "Ange gränsvärde: ";
    std::cin >> rule.limit;

    std::cout << "Larm om över (1) eller under (0) gränsen?: ";
    int choice;
    std::cin >> choice;
    rule.isOverLimit = (choice == 1);

    thresholds.addRule(rule);
}

int main() {
    // Skapa sensorer
    std::vector<std::unique_ptr<Sensor>> sensors;
    sensors.push_back(std::make_unique<TemperatureSensor>());
    sensors.push_back(std::make_unique<HumiditySensor>());
    sensors.push_back(std::make_unique<PressureSensor>());

    MeasurementStorage storage;
    ThresholdSystem thresholds;

    bool running = true;

    while (running) {
        printMenu();

        int choice;
        std::cin >> choice;

        // Hantera felaktig input
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Felaktig inmatning. Försök igen.\n";
            continue;
        }

        switch (choice) {
            case 1:
                readAllSensors(sensors, storage, thresholds);
                break;

            case 2:
                showStatistics(storage);
                break;

            case 3:
                storage.printAll();
                break;

            case 4:
                addThresholdRule(thresholds);
                break;

            case 5:
                thresholds.printAlarms();
                break;

            case 6:
                storage.saveToFile("data.txt");
                std::cout << "Data sparad till data.txt\n";
                break;

            case 7:
                storage.loadFromFile("data.txt");
                std::cout << "Data laddad från data.txt\n";
                break;

            case 8:
                std::cout << "Avslutar programmet...\n";
                running = false;
                break;

            default:
                std::cout << "Ogiltigt val. Välj 1-8.\n";
                break;
        }
    }

    return 0;
}