//
// Created by ACER on 26.02.2024.
//

#include "Hotel.h"
int Hotel::numberOfHotels = 0;

Hotel::Hotel()
: Hotel{"None", 0, "None"}{
    numberOfHotels++;
}
Hotel::Hotel(const std::string &name, int apartments, const std::string &rank)
    : hotelName{name},numberOfApartments{apartments},ranking{rank} {
    numberOfHotels++;
}
Hotel::~Hotel() {
    numberOfHotels--;
}

int Hotel::showApartments() {

}
