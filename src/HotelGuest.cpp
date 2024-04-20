//
// Created by Michael Corn on 4/17/24.
//

#include "HotelGuest.h"

std::string HotelGuest::getName()
{
    return name;
}

void HotelGuest::assignRoom(std::string room, double amount)
{
    roomType = room;
    bill = amount;
}

std::string HotelGuest::getRoom()
{
    return roomType;
}

double HotelGuest::getBill()
{
    return bill;
}
