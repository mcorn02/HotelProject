//
// Created by Michael Corn on 4/17/24.
//

#include "Penthouse.h"

Penthouse::Penthouse(double price, int roomNum, const std::string &view) : HotelRoom(price, roomNum, view) {}

double Penthouse::getPrice()
{
    return roomPrice;
}

std::string Penthouse::getRoomView()
{
    return roomView;
}