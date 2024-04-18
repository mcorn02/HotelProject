//
// Created by Michael Corn on 4/17/24.
//

#ifndef HOTELPROJECT_DELUXESUITE_H
#define HOTELPROJECT_DELUXESUITE_H
#include "HotelRoom.h"


class DeluxeSuite : public HotelRoom {
public:
    DeluxeSuite(double price = 350.0, const std::string& view = "Deluxe Suite");
    double getPrice();
    std::string getRoomView();
};


#endif //HOTELPROJECT_DELUXESUITE_H
