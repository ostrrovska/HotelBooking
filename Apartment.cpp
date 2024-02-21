#include "Apartment.h"
#include <iostream>

void Apartment::getApartmentInfo() {
    std::cout << hotelName
    << typeOfApartment
    << apartmentNumber
    << numberOfRooms
    << price;
}
Apartment::Apartment()
        : Apartment{"None","None",0,0,0}{}//delegating
Apartment::Apartment(const std::string &hotelName)
        :Apartment{hotelName, "None",0,0,0}{}
Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment)
        :Apartment{hotelName, typeOfApartment, 0,0,0} {}
Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber)
: Apartment{hotelName, typeOfApartment, apartmentNumber,0,0}{}
Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber, int numberOfRooms)
:Apartment{hotelName, typeOfApartment, apartmentNumber, numberOfRooms,0}{}
Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber, int numberOfRooms, int price)
:hotelName{hotelName}, typeOfApartment{typeOfApartment}, apartmentNumber{apartmentNumber}, numberOfRooms{numberOfRooms}, price{price}{}//initialisation list

