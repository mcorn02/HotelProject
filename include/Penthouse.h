//
// Created by Michael Corn on 4/17/24.
//

#ifndef HOTELPROJECT_PENTHOUSE_H
#define HOTELPROJECT_PENTHOUSE_H
#include "HotelRoom.h"


class Penthouse : public HotelRoom {
public:
    Penthouse(double price = 1135.0, const std::string& view = "Penthouse");
    double getPrice();
    std::string getRoomView();
};


#endif //HOTELPROJECT_PENTHOUSE_H
