// Renter.h
#ifndef RENTER_H
#define RENTER_H

#include <string>

class Renter {
public:
    std::string firstName;
    std::string lastName;
    int index;

    Renter(const std::string& firstName, const std::string& lastName);
};

#endif // RENTER_H
