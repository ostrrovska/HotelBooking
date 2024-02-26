cmake_minimum_required(VERSION 3.26)
project(RestaurantBooking)

set(CMAKE_CXX_STANDARD 17)

add_executable(RestaurantBooking main.cpp
        Apartment.cpp
        Apartment.h
        Customer.cpp
        Customer.h
        Booking.cpp
        Booking.h
        Hotel.cpp
        Hotel.h)
