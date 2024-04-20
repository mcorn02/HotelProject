//
// Created by Michael Corn on 4/16/24.
//

#include "ReservationSystem.h"
#include "HotelRoom.h"
#include "HotelGuest.h"
#include <regex>

void ReservationSystem::mainMenu()
{
    int choice;
    do {
        std::cout << "Enter 1 to assign room\n";
        std::cout << "Enter 2 to print daily report\n";
        std::cout << "Enter 99 to quit \n";

        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        switch (choice) {
            case 1:
                roomMenu();
                mainMenu();
                break;
            case 2:
                printDailyReport();
                mainMenu();
                break;
            case 99:
                exit(0);
            default:
                std::cout << "Not a valid input\n";
                break;
        }
    } while(choice != 99);
}

void ReservationSystem::printRoomData()
{
    std::cout << "TOTAL ROOMS AVAILABLE: " << totalRooms << "\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "Standard Courtyard Rooms available: " << courtYardRooms << ", Rate: $" << courtYardPrice << "\n";
    std::cout << "\n";
    std::cout << "Standard Scenic Rooms available: " << scenicRooms << ", Rate: $" << scenicPrice  << "\n";
    std::cout << "\n";
    std::cout << "Deluxe Suites available: " << deluxeRooms << ", Rate: $" << deluxeSuitePrice   << "\n";
    std::cout << "\n";
    std::cout << "Penthouse Suites available: " << penthouseRooms << ", Rate: $" << penthousePrice << "\n";
    std::cout << "\n";
}

void ReservationSystem::roomMenu()
{
    std::string roomType;
    std::string guestName;
    std::cout << "\nEnter guest's name: ";
    std::cin >> guestName;
    std::cout << "\n";


    std::unique_ptr<HotelGuest> guest = std::make_unique<HotelGuest>(guestName);


    printRoomData();

    std::cout << "What room type would they like?\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "Enter 1 for Standard Room Courtyard\n";
    std::cout << "Enter 2 for Standard Room Scenic\n";
    std::cout << "Enter 3 for Deluxe Suite\n";
    std::cout << "Enter 4 for Penthouse\n";
    std::cin >> roomType;


    if(!validateRoomInput(roomType))
    {
        std::cout << "Invalid input" << std::endl;
    }

    int intRoom = stoi(roomType);

    switch (intRoom)
    {
        case 1:
            if(!courtyardRoomVec.empty())
            {
                guest->assignRoom(courtyardRoomVec[0]->getRoomView(), courtYardPrice);
                std::cout << "\n";
                std::cout << guest->getName() << " has been assigned a " << guest->getRoom() << " for $" << courtYardPrice << "\n";
                std::cout << "\n";
                courtyardRoomVec.pop_back();
                courtYardRooms--;
                totalRooms--;
                updateRevenue(courtYardPrice);
                guestDataVec.push_back(std::move(guest));
            }
            else
            {
                std::cout << "No courtyard rooms available.\n";
            }
            break;
        case 2:
            if(!scenicRoomsVec.empty())
            {
                guest->assignRoom(scenicRoomsVec[0]->getRoomView(), scenicPrice);
                std::cout << "\n";
                std::cout << guest->getName() << " has been assigned a " << guest->getRoom() << " for $" << scenicPrice << "\n";
                std::cout << "\n";
                scenicRoomsVec.pop_back();
                scenicRooms--;
                totalRooms--;
                updateRevenue(scenicPrice);
                guestDataVec.push_back(std::move(guest));
            }
            else
            {
                std::cout << "No scenic rooms available.\n";
            }
            break;
        case 3:
            if(!deluxeSuiteVec.empty())
            {
                guest->assignRoom(deluxeSuiteVec[0]->getRoomView(), deluxeSuitePrice);
                std::cout << "\n";
                std::cout << guest->getName() << " has been assigned a " << guest->getRoom() << " for $" << deluxeSuitePrice << "\n";
                std::cout << "\n";
                deluxeSuiteVec.pop_back();
                deluxeRooms--;
                totalRooms--;
                updateRevenue(deluxeSuitePrice);
                guestDataVec.push_back(std::move(guest));
            }
            else
            {
                std::cout << "No deluxe suites available.\n";
            }
            break;
        case 4:
            if(!penthouseVec.empty())
            {
                guest->assignRoom(penthouseVec[0]->getRoomView(), penthousePrice);
                std::cout << "\n";
                std::cout << guest->getName() << " has been assigned a " << guest->getRoom() << " for $" << penthousePrice << "\n";
                std::cout << "\n";
                penthouseVec.pop_back();
                penthouseRooms--;
                totalRooms--;
                updateRevenue(penthousePrice);
                guestDataVec.push_back(std::move(guest));
            }
            else
            {
                std::cout << "No penthouse suites available.\n";
            }
            break;
        default:
            std::cout << "Invalid input";
            mainMenu();
    }
}

bool ReservationSystem::validateRoomInput(std::string& inp)
{
    std::regex pattern("[1234]");
    return std::regex_match(inp, pattern);
}

void ReservationSystem::setDate(std::string date)
{
    todaysDate = date;
}

std::string ReservationSystem::getdate()
{
    return todaysDate;
}

void ReservationSystem::updateRevenue(double amount)
{
    dailyRevenue += amount;
}

double ReservationSystem::getRevenue()
{
    return dailyRevenue;
}

void ReservationSystem::printDailyReport()
{
    std::cout << "DAILY REPORT\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "Daily Revenue: $" << getRevenue() << "\n";
    std::cout << "\n";
    std::cout << "GUEST DATA" << "\n";
    std::cout << "-------------------------------------------------\n";
    for(auto& guest : guestDataVec)
    {
        std::cout << "Name: " << guest->getName() << ", Room: " << guest->getRoom() << " Rate: $" << guest->getBill() << "\n";
        std::cout << "\n";
    }
    std::cout << "\n";

    printRoomData();

    std::cout << "\n";
}
