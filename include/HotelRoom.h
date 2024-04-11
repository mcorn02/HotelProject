//
// Created by Michael Corn on 4/9/24.
//

#ifndef HOTELPROJECT_HOTELROOM_H
#define HOTELPROJECT_HOTELROOM_H
#include <iostream>

class HotelRoom {
protected:
    std::string roomType;
    int roomPrice;
    int roomTotal;
public:
    virtual double getTotal() const = 0;
    virtual double getPrice() const = 0;
    virtual ~HotelRoom() {}
};


#endif //HOTELPROJECT_HOTELROOM_H
