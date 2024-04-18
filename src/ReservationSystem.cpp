//
// Created by Michael Corn on 4/16/24.
//

#include "ReservationSystem.h"
#include "HotelRoom.h"
#include "StandardRoomCourtyard.h"
#include "StandardRoomScenic.h"
#include "HotelGuest.h"


void ReservationSystem::menu()
{
   std::cout << "Welcome to the Hotel Michael's Reservation System" << std::endl;
   std::cout << "Please enter today's date (MM/DD/YYYY): ";
   std::cin >> todaysDate;
}

void ReservationSystem::printRoomData()
{
    std::cout << "TOTAL ROOMS AVAILABLE: " << HotelRooms.size() << "\n";



    for(auto& room : HotelRooms)
    {
        std::cout << "Room Type: " << room->getRoomView() << " Cost: $" << room->getPrice() << "\n";
    }
}

void ReservationSystem::assignRoom()
{
    std::string guestName;
    std::string roomType;
    std::cout << "Enter guest's name: ";
    std::cin >> guestName;

    HotelGuest guest(guestName);


    std::cout << "What room type would they like?";
    std::cin >> roomType;

    std::transform(roomType.begin(), roomType.end(), roomType.begin(), ::tolower);

}

