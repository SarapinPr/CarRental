// Car.cpp
#include "Car.h"
#include <cstdlib>
#include <ctime>

Car::Car(const std::string& brand, const std::string& model, int year, const std::string& bodyType, const std::string& carClass)
    : brand(brand), model(model), year(year), bodyType(bodyType), carClass(carClass), available(true) {
    distance = static_cast<float>(rand()) / RAND_MAX * 9.9 + 0.1;
}
