#include "ReservationSystem.h"
#include "HotelGuest.h"
#include <iostream>
using namespace std;


int main()
{
    ReservationSystem reservationSystem;

    std::string date;
    std::cout << "Welcome to the Hotel Michael's Reservation System" << std::endl;
    std::cout << "-------------------------------------------------\n";
    std::cout << "Please enter today's date (MM/DD/YYYY): ";
    std::cin >> date;
    std::cout << "-------------------------------------------------\n";

    reservationSystem.setDate(date);

    std::cout << "Today's date is " << reservationSystem.getdate() << std::endl;
    std::cout << "-------------------------------------------------\n";

    reservationSystem.mainMenu();
    return 0;
}
