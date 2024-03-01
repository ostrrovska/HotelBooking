#include "Apartment.h"
#include <iostream>

void Apartment::getApartmentInfo() {
    std::cout << "Hotel name: " << hotelName <<std::endl;
    std::cout << "Type of apartment: " << typeOfApartment << std::endl;
    std::cout << "Apartment number: " << apartmentNumber << std::endl;
    std::cout << "Number of rooms: " << numberOfRooms << std::endl;
    std:: cout << "Price: " << price << std::endl;
}

Apartment::Apartment()
        : Apartment{"None","None", 0, 0, 0} {} //делегування

Apartment::Apartment(const std::string &hotelName)
        : Apartment{hotelName,"None",0,0,0} {}

Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment)
        : Apartment{hotelName, typeOfApartment, 0, 0, 0} {}

Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber)
        : Apartment{hotelName, typeOfApartment, apartmentNumber, 0, 0} {}

Apartment::Apartment(const std::string &hotelName,const std::string &typeOfApartment, int apartmentNumber, int numberOfRooms)
        : Apartment{hotelName, typeOfApartment, apartmentNumber, numberOfRooms, 0} {}
Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber, int numberOfRooms, int price)
        : Hotel{hotelName}, typeOfApartment{typeOfApartment}, apartmentNumber{apartmentNumber}, numberOfRooms{numberOfRooms}, price{price} {}

Apartment::~Apartment() {std::cout << "Destructor called for apartment: " << this->apartmentNumber << std::endl;}//використання this


