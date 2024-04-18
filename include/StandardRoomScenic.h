//
// Created by Michael Corn on 4/9/24.
//

#ifndef HOTELPROJECT_STANDARDROOMSCENIC_H
#define HOTELPROJECT_STANDARDROOMSCENIC_H
#include "HotelRoom.h"

class StandardRoomScenic : public HotelRoom {
public:
    StandardRoomScenic(double price = 145.0, const std::string& roomView = "Standard Room, Scenic");
    double getPrice();
    std::string getRoomView();
};


#endif //HOTELPROJECT_STANDARDROOMSCENIC_H
