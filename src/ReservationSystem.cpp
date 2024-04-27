//
// Created by Michael Corn on 4/16/24.
//

#include "ReservationSystem.h"
#include "HotelRoom.h"
#include "HotelGuest.h"
#include <regex>

void ReservationSystem::mainMenu()
{
    std::cout << "Welcome to the Hotel Michael's Reservation System" << std::endl;
    std::cout << "-------------------------------------------------\n";

    //handles date format
    bool validDate = false;
    while(!validDate)
    {
        std::cout << "Please enter today's date (MM-DD-YYYY): ";
        std::cin >> todaysDate;

        if(!validateDateInput(todaysDate))
        {
            std::cout << "Invalid date format, Please enter date with format MM-DD-YYYY\n";
        }
        else
        {
            validDate = true;
        }
    }

    std::cout << "-------------------------------------------------\n";
    setDate(todaysDate);
    std::cout << "Today's date is " << getdate() << std::endl;
    std::cout << "-------------------------------------------------\n";


    int choice;
    do {
        std::cout << "Enter 1 to assign room\n";
        std::cout << "Enter 2 to show available rooms\n";
        std::cout << "Enter 3 to show daily revenue\n";
        std::cout << "Enter 4 to print daily report and save to file\n";
        std::cout << "Enter 5 to open file from a previous day\n";
        std::cout << "Enter 99 to quit \n";

        std::cin >> choice;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                roomMenu();
                break;
            case 2:
                printAvailableRooms();
                break;
            case 3:
                std::cout << "Revenue for " << todaysDate << "\n";
                std::cout << "-------------------------------------------------\n";
                std::cout << "$" << getRevenue() << "\n";
                std::cout << "\n";
                break;
            case 4:
                printDailyReport();
                writeRoomDataToFile();
                break;
            case 5:
                openFileFromPreviousDay();
                break;
            case 99:
                exit(0);
            default:
                std::cout << "Not a valid input\n";
                break;
        }
    } while(choice != 99);
}

void ReservationSystem::printAvailableRooms()
{
    std::cout << "TOTAL ROOMS AVAILABLE: " << totalRooms << "\n";
    std::cout << "-------------------------------------------------\n";
    std::cout << "Standard Courtyard Rooms available: " << courtyardRoomVec.size() << ", Rate: $" << courtYardPrice << "\n";
    std::cout << "\n";
    std::cout << "Standard Scenic Rooms available: " << scenicRoomsVec.size() << ", Rate: $" << scenicPrice  << "\n";
    std::cout << "\n";
    std::cout << "Deluxe Suites available: " << deluxeSuiteVec.size() << ", Rate: $" << deluxeSuitePrice   << "\n";
    std::cout << "\n";
    std::cout << "Penthouse Suites available: " << penthouseVec.size() << ", Rate: $" << penthousePrice << "\n";
    std::cout << "\n";
}

void ReservationSystem::roomMenu()
{
    std::string roomType;
    std::string guestName;
    std::cout << "\nEnter guest's name: ";
    std::cin >> guestName;
    std::cout << "\n";

    //creates a new guest object
    std::unique_ptr<HotelGuest> guest = std::make_unique<HotelGuest>(guestName);
    printAvailableRooms();

    std::cout << "What room type would " << guest->getName() << " like?\n";
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

    //string to int conversion
    int intRoom = stoi(roomType);

    switch (intRoom)
    {
        case 1:
            if(!courtyardRoomVec.empty())
            {
                //Get the StandardRoomCourtyard object from the unique_ptr
                StandardRoomCourtyard courtyardRoom = std::move(*courtyardRoomVec.back());
                courtyardRoomVec.pop_back(); //Remove the room from the vector

                //Assign the room data to the guest
                guest->assignRoom("Standard Courtyard", courtyardRoom.getRoomNum(), courtyardRoom.getPrice());

                std::cout << "\n";
                std::cout << guest->getName() << " has been assigned a " << guest->getRoomType() << ", Room Number: " << guest->getRoomNum() << " for $" << guest->getPrice() << "\n";
                std::cout << "\n";

                courtYardRoomsCount--;
                totalRooms--;
                updateRevenue(guest->getPrice());
                guestDataVec.push_back(std::move(guest)); //Move the guest object into the vector
            }
            else
            {
                std::cout << "No courtyard rooms available.\n";
            }
            break;
        case 2:
            if(!scenicRoomsVec.empty())
            {
                StandardRoomScenic scenicRoom = std::move(*scenicRoomsVec.back());
                scenicRoomsVec.pop_back();

                guest->assignRoom("Standard Scenic", scenicRoom.getRoomNum(), scenicRoom.getPrice());

                std::cout << "\n";
                std::cout << guest->getName() << " has been assigned a " << guest->getRoomType() << ", Room Number: " << guest->getRoomNum() << " for $" << guest->getPrice() << "\n";
                std::cout << "\n";

                scenicRoomsCount--;
                totalRooms--;
                updateRevenue(guest->getPrice());
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
                DeluxeSuite deluxeRoom = std::move(*deluxeSuiteVec.back());
                deluxeSuiteVec.pop_back();

                guest->assignRoom("Deluxe Suite", deluxeRoom.getRoomNum(), deluxeRoom.getPrice());

                std::cout << "\n";
                std::cout << guest->getName() << " has been assigned a " << guest->getRoomType() << ", Room Number: " << guest->getRoomNum() << " for $" << guest->getPrice() << "\n";
                std::cout << "\n";

                deluxeRoomsCount--;
                totalRooms--;
                updateRevenue(guest->getPrice());
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
                Penthouse penthouseRoom = std::move(*penthouseVec.back());
                penthouseVec.pop_back();

                guest->assignRoom("Penthouse", penthouseRoom.getRoomNum(), penthouseRoom.getPrice());

                std::cout << "\n";
                std::cout << guest->getName() << " has been assigned a " << guest->getRoomType() << ", Room Number: " << guest->getRoomNum() << " for $" << guest->getPrice() << "\n";
                std::cout << "\n";

                penthouseRoomsCount--;
                totalRooms--;
                updateRevenue(guest->getPrice());
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

bool ReservationSystem::validateDateInput(std::string &inp)
{
    std::regex pattern("^(0[1-9]|1[0-2])-(0[1-9]|1\\d|2\\d|3[01])-(19|20)\\d{2}$");
    return std::regex_match(inp, pattern);
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
    printGuestDataVec();
    printAvailableRooms();
}

void ReservationSystem::writeRoomDataToFile()
{ //Open the file for writing
    std::ofstream outFile("hotel_data_" + todaysDate + ".txt");

    //Check if the file was opened successfully
    if (!outFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    //Write room data to the file
    outFile << todaysDate << "\n";
    outFile << "ROOM DATA\n";
    outFile << "-------------------------------------------------\n";
    outFile << "TOTAL ROOMS AVAILABLE: " << totalRooms << "\n";
    outFile << "Standard Courtyard Rooms available: " << courtYardRoomsCount << ", Rate: $" << courtYardPrice << "\n";
    outFile << "Standard Scenic Rooms available: " << scenicRoomsCount << ", Rate: $" << scenicPrice  << "\n";
    outFile << "Deluxe Suites available: " << deluxeRoomsCount << ", Rate: $" << deluxeSuitePrice   << "\n";
    outFile << "Penthouse Suites available: " << penthouseRoomsCount << ", Rate: $" << penthousePrice << "\n\n";

    //Write guest data to the file
    outFile << "GUEST DATA\n";
    outFile << "-------------------------------------------------\n";
    for(const auto& guest : guestDataVec)
    {
       outFile << "Name: " << guest->getName() << ", Room: " << guest->getRoomNum() << ", Rate: $" << guest->getPrice() << "\n";
    }
    outFile << "\n";

    // Close the file
    outFile.close();


    //Check if the file was closed successfully
    if (!outFile) {
        std::cerr << "Error closing file!" << std::endl;
        return;
    }
    std::cout << "File saved successfully\n";
    std::cout << "\n";
}

void ReservationSystem::openFileFromPreviousDay()
{
        std::string fileName;
        std::cout << "Enter file name from previous day (ex: hotel_data_01-01-2000.txt): ";
        std::cin >> fileName;
        std::cout << "\n";

        std::cout << "Attempting to open file: " << fileName << "\n";
        std::cout << "\n";

        // Attempt to open the file
        std::ifstream inFile(fileName);
        if (inFile.is_open()) {
            std::cout << "File found. Contents:\n";
            std::string line;
            while (std::getline(inFile, line)) {
                std::cout << line << std::endl;
            }
            inFile.close();
        } else {
            std::cerr << "Error opening file or file not found.\n";
        }
        std::cout << "\n";
}

void ReservationSystem::printGuestDataVec() {
    for (auto& guest: guestDataVec) {
        if (guest) {
            std::cout << "Name: " << guest->getName() << ", Room Type: " << guest->getRoomType() << ", Room Number: " << guest->getRoomNum() << ", Price: $" << guest->getPrice() << "\n";
            std::cout << "\n";
        }
        else
        {
            std::cout << "guest has not been assigned a room\n";
        }
    }
}