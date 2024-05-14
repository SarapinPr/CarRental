// Car.h
#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
public:
    std::string brand;
    std::string model;
    int year;
    std::string bodyType;
    std::string carClass;
    bool available;
    float distance;

    Car(const std::string& brand, const std::string& model, int year, const std::string& bodyType, const std::string& carClass);
};

#endif // CAR_H
