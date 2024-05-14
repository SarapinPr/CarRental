// Administrator.h
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "CarRentalSystem.h"

class Administrator {
public:
    void displayMainMenu() const;
    void addNewCar(CarRentalSystem& rentalSystem);
    void displayAllCars(const CarRentalSystem& rentalSystem) const;
    void removeCarFromSystem(CarRentalSystem& rentalSystem);
    void displayUserMessages(const CarRentalSystem& rentalSystem) const;
    void openChatWithUser(CarRentalSystem& rentalSystem);
};

#endif // ADMINISTRATOR_H
