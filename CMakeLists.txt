cmake_minimum_required(VERSION 3.27)
project(HotelProject)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(HotelProject src/main.cpp
        src/HotelRoom.cpp
        include/HotelRoom.h
        src/StandardRoomCourtyard.cpp
        include/StandardRoomCourtyard.h
        src/StandardRoomScenic.cpp
        include/StandardRoomScenic.h)
