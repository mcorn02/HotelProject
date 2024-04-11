//
// Created by Michael Corn on 4/9/24.
//

#include "../include/StandardRoomScenic.h"

StandardRoomScenic::StandardRoomScenic()
{
    const std::string roomType = "Standard Room, Scenic";
    const int roomPrice = 145;
    const int roomTotal = 35;
}

double StandardRoomScenic::getPrice() const
{
    return roomPrice;
}

double StandardRoomScenic::getTotal() const
{
    return roomTotal;
}