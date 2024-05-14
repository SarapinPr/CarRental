// Reservation.h
#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation {
public:
    int userIndex;
    int carIndex;
    bool active;

    Reservation(int userIndex, int carIndex);
};

#endif // RESERVATION_H
