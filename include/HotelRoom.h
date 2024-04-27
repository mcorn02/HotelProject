//
// Created by Michael Corn on 4/9/24.
//

#ifndef HOTELPROJECT_HOTELROOM_H
#define HOTELPROJECT_HOTELROOM_H
#include <iostream>

class HotelRoom {
protected:
    std::string roomView;
    double roomPrice;
    int roomNumber;
public:
    HotelRoom(double price, int roomNum, const std::string& view) : roomPrice(price), roomNumber(roomNum), roomView(view) {};

    double getPrice()
    {
        return roomPrice;
    }

    int getRoomNum()
    {
        return roomNumber;
    }

    std::string getRoomView()
    {
        return roomView;
    }
    virtual ~HotelRoom() {}
};


#endif //HOTELPROJECT_HOTELROOM_H
