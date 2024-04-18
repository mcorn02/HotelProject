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
public:
    HotelRoom(double price, const std::string& view) : roomPrice(price), roomView(view) {};
    double getPrice()
    {
        return roomPrice;
    }
    std::string getRoomView()
    {
        return roomView;
    }
    virtual ~HotelRoom() {}
};


#endif //HOTELPROJECT_HOTELROOM_H
