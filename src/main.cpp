#include "StandardRoomCourtyard.cpp"
#include "StandardRoomScenic.cpp"
#include <HotelRoom.h>

int main()
{
    std::vector<HotelRoom*> HotelRooms;
    HotelRooms.push_back(new StandardRoomScenic());
    HotelRooms.push_back(new StandardRoomCourtyard);


    return 0;
}
