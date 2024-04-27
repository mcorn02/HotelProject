//
// Created by Michael Corn on 4/17/24.
//

#include "HotelGuest.h"

std::string HotelGuest::getName()
{
    return name;
}

std::string HotelGuest::getRoomType()
{
    return roomType;
}

int HotelGuest::getRoomNum()
{
    return roomNumber;
}

double HotelGuest::getPrice()
{
    return price;
}

void HotelGuest::assignRoom(const std::string& type, int number, double roomPrice) {
    roomType = type;
    roomNumber = number;
    price = roomPrice;
}

void HotelGuest::printRoomData()
{
    //std::cout << "Name: " << name << " Assigned Room Type: " << getAssignedRoom()->getRoomView() << ", Room Number: " << getAssignedRoom()->getRoomNum() << ", Room Price: $" << getAssignedRoom()->getPrice() << "\n";
}
