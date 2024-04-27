//
// Created by Michael Corn on 4/9/24.
//

#include "../include/StandardRoomScenic.h"

StandardRoomScenic::StandardRoomScenic(double price, int roomNum, const std::string& view) : HotelRoom(price, roomNum, view) {}

double StandardRoomScenic::getPrice() {
    return roomPrice;
}

std::string StandardRoomScenic::getRoomView()
{
    return roomView;
}
