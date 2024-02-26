#include "Apartment.h"
#include <iostream>

void Apartment::getApartmentInfo() {
    std::cout << "Type of apartment: " << typeOfApartment << std::endl
              << "Number: " << apartmentNumber << std::endl
              << "Number of rooms: " << numberOfRooms << std::endl
              << "Price: " << price << std::endl;
}

Apartment::Apartment()
        : Apartment{"None", 0, 0, 0} {} //делегування
Apartment::Apartment(const std::string &typeOfApartment)
        : Apartment{typeOfApartment, 0, 0, 0} {}
Apartment::Apartment(const std::string &typeOfApartment, int apartmentNumber)
        : Apartment{typeOfApartment, apartmentNumber, 0, 0} {}
Apartment::Apartment(const std::string &typeOfApartment, int apartmentNumber, int numberOfRooms)
        : Apartment{typeOfApartment, apartmentNumber, numberOfRooms, 0} {}
Apartment::Apartment(const std::string &typeOfApartment, int apartmentNumber, int numberOfRooms, int price)
        : typeOfApartment{typeOfApartment}, apartmentNumber{apartmentNumber}, numberOfRooms{numberOfRooms}, price{price} {} // ініціалізація членів класу
Apartment::~Apartment() {std::cout << "Destructor called for apartment: " << this->apartmentNumber << std::endl;}//використання this


