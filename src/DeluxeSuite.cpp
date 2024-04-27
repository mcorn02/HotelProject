//
// Created by Michael Corn on 4/17/24.
//

#include "DeluxeSuite.h"

DeluxeSuite::DeluxeSuite(double price, int roomNum, const std::string &view) : HotelRoom(price, roomNum, view) {}

double DeluxeSuite::getPrice()
{
    return roomPrice;
}

std::string DeluxeSuite::getRoomView()
{
    return roomView;
}