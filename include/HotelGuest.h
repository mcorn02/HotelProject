//
// Created by Michael Corn on 4/17/24.
//

#ifndef HOTELPROJECT_HOTELGUEST_H
#define HOTELPROJECT_HOTELGUEST_H
#include <string>

class HotelGuest {
private:
    const std::string name;
public:
    HotelGuest(const std::string guestName) : name(guestName) {}
    std::string getName();
};


#endif //HOTELPROJECT_HOTELGUEST_H
