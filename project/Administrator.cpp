// Administrator.cpp
#include "Administrator.h"
#include <iostream>
#include "CarRentalSystem.h"
using namespace std;

void Administrator::displayMainMenu() const {
    cout << "Witaj, Administratorze!\n";
    cout << "1. Dodaj nowy samochod do floty\n";
    cout << "2. Wyswietl liste wszystkich samochodow\n";
    cout << "3. Usun samochod z listy\n";
    cout << "4. Pokaz wiadomosci od uzytkownikow\n"; 
    cout << "5. Wyjscie do menu wyboru uzytkownikow\n";
}
void Administrator::addNewCar(CarRentalSystem& rentalSystem) {
        string brand, model, bodyType, carClass;
        int year;

        cout << "Podaj marke samochodu: ";
        cin >> brand;
        cout << "Podaj model samochodu: ";
        cin >> model;
        cout << "Podaj rok produkcji: ";
        cin >> year;
        cout << "Podaj typ karoserii: ";
        cin >> bodyType;
        cout << "Podaj klase auta (ekonom, biznes, premium): ";
        cin >> carClass;

        rentalSystem.addCar(brand, model, year, bodyType, carClass);
        cout << "Dodano nowy samochod do floty: " << brand << " " << model << " (Rok produkcji: " << year << ", Typ karoserii: " << bodyType << ", Klasa auta: " << carClass << ")\n";
    }

    void Administrator::displayAllCars(const CarRentalSystem& rentalSystem) const {
        rentalSystem.displayAvailableCars();
    }
    void Administrator::removeCarFromSystem(CarRentalSystem& rentalSystem) {
        cout << "Lista dostepnych samochodow do usuniecia:\n";
        rentalSystem.displayAvailableCars();

        int carIndex;
        cout << "Podaj numer samochodu do usuniecia: ";
        cin >> carIndex;

        if (carIndex >= 0 && carIndex < static_cast<int>(rentalSystem.getCars().size())) {
            rentalSystem.removeCar(carIndex);
            cout << "Usunieto samochod z floty.\n";
        } else {
            cout << "Niepoprawny numer samochodu.\n";
        }
    }

    void Administrator::displayUserMessages(const CarRentalSystem& rentalSystem) const {
        rentalSystem.displayAdministratorChat();
    }
    void Administrator::openChatWithUser(CarRentalSystem& rentalSystem) {
        rentalSystem.displayUserMessages();
    }
