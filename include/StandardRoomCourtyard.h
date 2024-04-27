//
// Created by Michael Corn on 4/9/24.
//

#ifndef HOTELPROJECT_STANDARDROOMCOURTYARD_H
#define HOTELPROJECT_STANDARDROOMCOURTYARD_H
#include "HotelRoom.h"

class StandardRoomCourtyard : public HotelRoom {
public:
    StandardRoomCourtyard(double price, int roomNum, const std::string& view = "Standard Room, Courtyard");
    double getPrice();
    std::string getRoomView();
};


#endif //HOTELPROJECT_STANDARDROOMCOURTYARD_H
