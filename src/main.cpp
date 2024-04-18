#include "ReservationSystem.h"
#include "HotelGuest.h"
#include <iostream>
using namespace std;


int main()
{
    ReservationSystem reservationSystem;
    reservationSystem.printRoomData();
    string name;

    cout << "Enter guest's name: ";
    cin >> name;

    HotelGuest guest1(name);

    cout << "Guest name: "  << guest1.getName() << "\n";

    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);

    std::cout << "Memory usage: " << usage.ru_maxrss << " kilobytes" << std::endl;

    return 0;
}
