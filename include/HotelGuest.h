//
// Created by Michael Corn on 4/17/24.
//

#ifndef HOTELPROJECT_HOTELGUEST_H
#define HOTELPROJECT_HOTELGUEST_H
#include <string>
#include "HotelRoom.h"

class HotelGuest {
private:
    const std::string name;
    std::string roomType;
    double bill;
public:
    HotelGuest(const std::string guestName) : name(guestName), roomType("") {}
    std::string getName();
    void assignRoom(std::string room, double amount);
    std::string getRoom();
    void printInfo() const;
    double getBill();
};


#endif //HOTELPROJECT_HOTELGUEST_H
