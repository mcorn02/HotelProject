//
// Created by Michael Corn on 4/9/24.
//

#include "../include/StandardRoomCourtyard.h"

StandardRoomCourtyard::StandardRoomCourtyard()
{
    const std::string roomType = "Standard Room, Courtyard";
    const int roomPrice = 125;
    const int roomTotal = 70;
}

double StandardRoomCourtyard::getPrice() const
{
    return roomPrice;
}

double StandardRoomCourtyard::getTotal() const
{
    return roomTotal;
}
