// CarRentalSystem.h
#ifndef CAR_RENTAL_SYSTEM_H
#define CAR_RENTAL_SYSTEM_H

#include "Car.h"
#include "Chat.h"
#include "Reservation.h"
#include <vector>

class CarRentalSystem {
private:
    std::vector<Car> cars;
    std::vector<int> rentedCars;
    std::vector<std::vector<int>> rentHistory;
    bool rentalInProgress;
    int currentRentedCarIndex;
    Chat chat;
    std::vector<Reservation> reservations;

public:
    CarRentalSystem();
    void addCar(const std::string& brand, const std::string& model, int year, const std::string& bodyType, const std::string& carClass);
    void displayAvailableCars() const;
    void displayRentedCars() const;
    void displayRentHistory(int userIndex) const;
    void rentCar(int userIndex, int carIndex);
    void endRental();
    bool isRentalInProgress() const;
    void openRentalSubMenu();
    void continueChat();
    const std::vector<Car>& getCars() const;
    void removeCar(int carIndex);
    void openChatWithAdministrator();
    void displayAdministratorChat() const;
    void displayUserMessages() const;
    void reserveCar(int userIndex, int carIndex);
    void displayReservations() const;
};

#endif // CAR_RENTAL_SYSTEM_H
