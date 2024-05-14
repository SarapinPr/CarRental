// CarOwner.h
#ifndef CAR_OWNER_H
#define CAR_OWNER_H

#include "CarRentalSystem.h"

class CarOwner {
public:
    void displayMainMenu() const;
    void addCarForRent(CarRentalSystem& rentalSystem, const std::string& brand, const std::string& model);
};

#endif // CAR_OWNER_H
