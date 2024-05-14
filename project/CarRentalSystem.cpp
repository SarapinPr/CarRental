// CarRentalSystem.cpp
#include "CarRentalSystem.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Implement the methods of CarRentalSystem class here
    CarRentalSystem::CarRentalSystem() : rentalInProgress(false), currentRentedCarIndex(-1) {}

    void CarRentalSystem::addCar(const string& brand, const string& model, int year, const string& bodyType, const string& carClass) {
        cars.emplace_back(brand, model, year, bodyType, carClass);
    }

    void CarRentalSystem::displayAvailableCars() const {
    cout << "Dostepne samochody:\n";
    for (int i = 0; i < static_cast<int>(cars.size()); ++i) {
        if (cars[i].available) {
            cout << i << ". " << cars[i].brand << " " << cars[i].model << " (Rok produkcji: " << cars[i].year << ", Typ karoserii: " << cars[i].bodyType << ", Klasa auta: " << cars[i].carClass << ") - Odleglosc: " << cars[i].distance << " km\n";
        }
    }
    }


    void CarRentalSystem::displayRentedCars() const {
        if (rentedCars.empty()) {
            cout << "Na ten moment nie wynajmujesz zadnego samochodu(.\n";
        } else {
            cout << "Wynajety samochod:\n";
            for (int index : rentedCars) {
                cout << cars[index].brand << " " << cars[index].model << " - Odleglosc: " << cars[index].distance << " km\n";
            }
        }
    }

    void CarRentalSystem::displayRentHistory(int userIndex) const {
    if (!rentHistory.empty() && userIndex < static_cast<int>(rentHistory.size()) && !rentHistory[userIndex].empty()) {
        cout << "Historia wynajmow:\n";
        const vector<int>& userHistory = rentHistory[userIndex];
        for (int index : userHistory) {
            cout << cars[index].brand << " " << cars[index].model << " - Odleglosc: " << cars[index].distance << " km\n";
        }
    } else {
        cout << "Jeszcze nie wynajmowales u nas samochodow.\n";
    }
    }   


    void CarRentalSystem::rentCar(int userIndex, int carIndex) {
    if (rentalInProgress) {
        cout << "Mozesz wynajac tylko jeden samochod naraz.\n";
        return;
    }
    if (carIndex >= 0 && carIndex < static_cast<int>(cars.size())) {
        if (cars[carIndex].available) {
            cout << "Wypozyczono: " << cars[carIndex].brand << " " << cars[carIndex].model << " - Odleglosc: " << cars[carIndex].distance << " km\n";
            cars[carIndex].available = false;

            if (userIndex >= static_cast<int>(rentHistory.size())) {
                rentHistory.resize(userIndex + 1);
            }

            rentedCars.push_back(carIndex);
            rentalInProgress = true;
            currentRentedCarIndex = carIndex;
            openRentalSubMenu();
        } else {
            cout << "Samochod niedostepny do wypozyczenia.\n";
        }
        } 
    else {
        cout << "Niepoprawny numer samochodu.\n";
    }
    }

    void CarRentalSystem::endRental() {
    rentalInProgress = false;
    int carIndex = currentRentedCarIndex;
    currentRentedCarIndex = -1;

    if (carIndex != -1) {
        cout << "Zakonczono wynajem samochodu " << cars[carIndex].brand << " " << cars[carIndex].model << "\n\n";
        cars[carIndex].available = true;

        auto it = find(rentedCars.begin(), rentedCars.end(), carIndex);
        if (it != rentedCars.end()) {
            rentedCars.erase(it);
        }

        rentHistory[0].push_back(carIndex);
    } else {
        cout << "Brak aktywnego wynajmu.\n";
    }
    }

    bool CarRentalSystem::isRentalInProgress() const {
        return rentalInProgress;
    }

    void CarRentalSystem::openRentalSubMenu() {
    while (true) {
        cout << "Jestes w menu wynajetego samochodu:\n";
        cout << "1. Zakoncz wynajem\n";
        cout << "2. Otworz czat z administratorem\n";
        cout << "3. Kontynuuj czat\n"; 
        cout << "4. Powrot do menu glownego\n";
        int option;
        cout << "Wybierz opcje: ";
        cin >> option;
        cout << "\n";

        if (option == 1) {

            endRental();
            break;
        } else if (option == 2) {

            openChatWithAdministrator();
        } else if (option == 3) {

            continueChat();
        } else if (option == 4) {

            break;
        } else {
            cout << "Niepoprawna opcja.\n";
        }
    }
    }
    void CarRentalSystem::continueChat() {
        while (true) {
            cout << "Jestes w trakcie czatu z administratorem:\n";
            cout << "1. Napisz wiadomosc\n";
            cout << "2. Powrot do menu wynajetego samochodu\n";
            int option;
            cout << "Wybierz opcje: ";
            cin >> option;
            cout << "\n";

            if (option == 1) {
                string messageContent;
                cout << "Napisz wiadomosc do administratora: ";
                cin.ignore();
                getline(cin, messageContent);
                chat.addMessage("User", messageContent);
                cout << "Wiadomosc wyslana do administratora.\n";
            } else if (option == 2) {
                break;
            } else {
                cout << "Niepoprawna opcja.\n";
            }
        }
    }
    const vector<Car>& CarRentalSystem::getCars() const {
        return cars;
    }

    void CarRentalSystem::removeCar(int carIndex) {
        if (carIndex >= 0 && carIndex < static_cast<int>(cars.size())) {
            cars.erase(cars.begin() + carIndex);
            
        } else {
            cout << "Niepoprawny numer samochodu.\n";
        }
    }
    void CarRentalSystem::openChatWithAdministrator() {
        string messageContent;
        cout << "Napisz wiadomosc do administratora: ";
        cin.ignore();
        getline(cin, messageContent);
        chat.addMessage("User", messageContent);
        cout << "Wiadomosc wyslana do administratora.\n";
        continueChat();
    }

    void CarRentalSystem::displayAdministratorChat() const {
        chat.displayChat();
    }

    void CarRentalSystem::displayUserMessages() const {
        displayAdministratorChat();
    }
    void CarRentalSystem::reserveCar(int userIndex, int carIndex) {
        reservations.emplace_back(userIndex, carIndex);
    }

    void CarRentalSystem::displayReservations() const {
        if (reservations.empty()) {
            cout << "Brak aktywnych rezerwacji.\n";
        } else {
            cout << "Aktywne rezerwacje:\n";
            for (const auto& reservation : reservations) {
                cout << "User " << reservation.userIndex << " reserved Car " << reservation.carIndex << "\n";
            }
        }
    }