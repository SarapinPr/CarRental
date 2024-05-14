#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include <algorithm>
#include "CarRentalSystem.h"
#include "CarOwner.h"
#include "Administrator.h"
#include "Renter.h"

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(0)));
    vector<Renter> renters;
    string firstName, lastName;

    CarRentalSystem rentalSystem;
    CarOwner carOwner;
    Administrator administrator;
    Renter renter(firstName, lastName);

    rentalSystem.addCar("Toyota", "Camry", 2022, "Sedan", "Business");
    rentalSystem.addCar("Ford", "Focus", 2021, "Hatchback", "Economy");
    rentalSystem.addCar("Honda", "Civic", 2023, "Sedan", "Premium");

    char userType;
    bool exitProgram = false;

    do {
        cout << "Witam w programie do wynajmu samochodow osobowych!\n Wybierz typ uzytkownika dla testowania programu\n\n 'O' - Wlasciciel samochodu(Mozliwosc wystawienia wlasnego samochod do wynajmu)\n 'R' - Wynajmujacy (W przypadku wynajmu samochodu dostepnego na liscie)\n 'A' - Administrator (do zarzadzania flota samochodow)\n 'Q' - Zakoncz program \n Wybierz opcje:";
        cin >> userType;
        cout << "\n";

        switch (userType) {
            case 'O':{
            case 'o':
                
                char ownerOption;
                do {
                    carOwner.displayMainMenu();
                    cout << "Wybierz opcje: ";
                    cin >> ownerOption;
                    cout << "\n";

                    switch (ownerOption) {
                        case '1':
                            {
                                string brand, model;
                                cout << "Podaj marke samochodu: ";
                                cin >> brand;
                                cout << "Podaj model samochodu: ";
                                cin >> model;
                                carOwner.addCarForRent(rentalSystem, brand, model);
                            }
                            break;

                        case '2':
                            cout << "Powrot do menu wyboru uzytkownikow.\n";
                            break;

                        default:
                            cout << "Niepoprawna opcja.\n";
                            break;
                    }

                } while (ownerOption != '2');
                break;
            }
            case 'R':{
            case 'r':

                if (renter.firstName.empty() && renter.lastName.empty()) {
                        cout << "Podaj swoje imie: ";
                        cin >> firstName;
                        cout << "Podaj swoje nazwisko: ";
                        cin >> lastName;
                        renter.firstName = firstName;
                        renter.lastName = lastName;
                        cout << "\n";
                    }
                int option;

                while (true) {
                    cout << "Witam w menu glownym na koncie " << renter.firstName << " " << renter.lastName << ".\n\n"
                    << "Z czego chcesz skorzystac tym razem?\n"
                    << "1. Pokaz liste dostepnych aut\n"
                    << "2. Pokaz menu z wynajetym samochodem\n"
                    << "3. Pokaz historie wynajmow\n"
                    << "4. Zarezerwuj samochod\n"
                    << "5. Wyjscie do menu wybora uzytkownikow\n"
                    << "Wybierz opcje: ";
                    cin >> option;
		            cout << "\n" ;

                    string answer;

                    switch (option) {
                        case 1:
                            rentalSystem.displayAvailableCars();
                            cout << "Podaj numer samochodu do wypozyczenia: " ;
                            int carIndex;
                            cin >> carIndex;
			                cout << " \n" ;
                            rentalSystem.rentCar(0, carIndex);
                            break;

                        case 2:
                            rentalSystem.displayRentedCars();
                            if (rentalSystem.isRentalInProgress()) {
                                rentalSystem.openRentalSubMenu();
                            }
                            break;

                        case 3:
                            rentalSystem.displayRentHistory(0);
                            break;
			            case 4:
                            cout << "Zarezerwuj samochod - Dostepne samochody:\n";
                            rentalSystem.displayAvailableCars();
                            cout << "Podaj numer samochodu do zarezerwowania: ";
                            int reserveCarIndex;
                            cin >> reserveCarIndex;
                            if (reserveCarIndex >= 0 && reserveCarIndex < rentalSystem.getCars().size()) {
                                rentalSystem.reserveCar(0, reserveCarIndex);
                                cout << "Zarezerwowano samochod.\n";

                                while (true) {
                                    cout << "Zarezerwuj samochod - Podmenu:\n";
                                    cout << "1. Zakoncz rezerwacje\n";
                                    cout << "2. Wynajmij samochod\n";
                                    cout << "3. Powrot do menu glownego\n";
                                    int reservationOption;
                                    cout << "Wybierz opcje: ";
                                    cin >> reservationOption;
                                    cout << "\n";

                                    switch (reservationOption) {
                                        case 1:
                                        cout << "Zakonczono rezerwacje.\n";
                                        break;

                                    case 2:
                                        rentalSystem.displayAvailableCars();
                                        cout << "Podaj numer samochodu do wypozyczenia: " ;
                                        int carIndex;
                                        cin >> carIndex;
                                        cout << " \n" ;
                                        rentalSystem.rentCar(0, carIndex);
                                        break;

                                    case 3:
                                        cout << "Powrot do menu glownego Wynajmujacego.\n";
                                        break;

                                    default:
                                        cout << "Niepoprawna opcja.\n";
                                        break;
                                    } 
                                    if (reservationOption == 1 or reservationOption == 3) {
                                        break;
                                    }
                                }
                            } else {
                            cout << "Niepoprawny numer samochodu.\n";
                            }
                            break;
                        case 5:
                        cout << "Powrot do menu glownego Wynajmujacego.\n";
                        break;
                                
                        case 6: 
                            rentalSystem.openChatWithAdministrator();
                            break;

                        default:
                            cout << "Niepoprawna opcja.\n";
                            break;
                    }
                        if (option == 5) {
                        break;
                        }
                }
                break;
            }     
            case 'A':{
            case 'a':
                char adminOption;
                do {
                    administrator.displayMainMenu();
                    cout << "Wybierz opcje: ";
                    cin >> adminOption;
                    cout << "\n";

                    switch (adminOption) {
                        case '1':
                            administrator.addNewCar(rentalSystem);
                            break;

                        case '2':
                            administrator.displayAllCars(rentalSystem);
                            break;

                        case '3':
                            administrator.removeCarFromSystem(rentalSystem);
                            break;

			            case '4':
    				        administrator.openChatWithUser(rentalSystem);
    				        break;
			            case '5':
                            cout << "Powrot do menu wyboru uzytkownikow.\n";
                            break;

                        default:
                            cout << "Niepoprawna opcja.\n";
                            break;
                    }

                } while (adminOption != '4');
                break;
            }

            case 'Q':{
            case 'q':
                cout << "Zakonczono program.\n";
                exitProgram = true;
                break;

            default:
                cout << "Niepoprawny typ uzytkownika.\n";
                break;
            }

        }
    } while (!exitProgram);

    return 0;
}