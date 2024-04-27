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
    int roomNumber;
    double price;
public:
    //HotelGuest(const std::string guestName) : name(guestName), assignedRoom(nullptr) {}
    HotelGuest(const std::string guestName) : name(guestName) {}
    std::string getName();
    std::string getRoomType();
    int getRoomNum();
    double getPrice();
    void assignRoom(const std::string& type, int num, double roomPrice);
    void printRoomData();
};


#endif //HOTELPROJECT_HOTELGUEST_H
