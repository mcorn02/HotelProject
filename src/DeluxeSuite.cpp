//
// Created by Michael Corn on 4/17/24.
//

#include "DeluxeSuite.h"

DeluxeSuite::DeluxeSuite(double price, const std::string &view) : HotelRoom(price, view) {}

double DeluxeSuite::getPrice()
{
    return roomPrice;
}

std::string DeluxeSuite::getRoomView()
{
    return roomView;
}