// CarOwner.cpp
#include "CarOwner.h"
#include <iostream>
using namespace std;
// Implementation of CarOwner member functions...
void CarOwner::displayMainMenu() const {
        cout << "Witaj, Wlascicielu Samochodu!\n";
        cout << "1. Dodaj samochod do wynajmu\n";
        cout << "2. Wyjscie do menu wyboru uzytkownikow\n";
    }	

    void CarOwner::addCarForRent(CarRentalSystem& rentalSystem, const string& brand, const string& model) {
        int year;
        string bodyType, carClass;
        
        cout << "Podaj rok produkcji: ";
        cin >> year;
        cout << "Podaj typ karoserii: ";
        cin >> bodyType;
        cout << "Podaj klase auta (ekonom, biznes, premium): ";
        cin >> carClass;

        rentalSystem.addCar(brand, model, year, bodyType, carClass);
        cout << "Dodano samochod do wynajmu: " << brand << " " << model << " (Rok produkcji: " << year << ", Typ karoserii: " << bodyType << ", Klasa auta: " << carClass << ")\n";
    }