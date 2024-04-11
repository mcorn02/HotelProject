//
// Created by Michael Corn on 4/9/24.
//

#ifndef HOTELPROJECT_STANDARDROOMCOURTYARD_H
#define HOTELPROJECT_STANDARDROOMCOURTYARD_H
#include "HotelRoom.h"

class StandardRoomCourtyard : public HotelRoom {
private:
    std::string roomView;
public:
    StandardRoomCourtyard();
    double getPrice() const override;
    double getTotal() const override;
};


#endif //HOTELPROJECT_STANDARDROOMCOURTYARD_H
