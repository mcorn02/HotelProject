//
// Created by Michael Corn on 4/9/24.
//

#include "../include/StandardRoomCourtyard.h"

StandardRoomCourtyard::StandardRoomCourtyard(double price, int roomNum, const std::string& view) : HotelRoom(price, roomNum, view) {}

double StandardRoomCourtyard::getPrice()
{
    return roomPrice;
}

std::string StandardRoomCourtyard::getRoomView()
{
    return roomView;
}


