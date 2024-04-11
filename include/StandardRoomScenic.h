//
// Created by Michael Corn on 4/9/24.
//

#ifndef HOTELPROJECT_STANDARDROOMSCENIC_H
#define HOTELPROJECT_STANDARDROOMSCENIC_H
#include "HotelRoom.h"

class StandardRoomScenic : public HotelRoom {
private:
    std::string roomView;
public:
    StandardRoomScenic();
    double getPrice() const override;
    double getTotal() const override;
};


#endif //HOTELPROJECT_STANDARDROOMSCENIC_H
