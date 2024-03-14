#include "Apartment.h"
#include <iostream>

void Apartment::getApartmentInfo() {
    std::cout << "Hotel name: " << hotelName <<std::endl;
    std::cout << "Type of apartment: " << typeOfApartment << std::endl;
    std::cout << "Apartment number: " << apartmentNumber << std::endl;
    std::cout << "Number of rooms: " << numberOfRooms << std::endl;
    std:: cout << "Price: " << price << std::endl;
}

void Apartment::showApartments(std::vector<Apartment> &apartments) {
    for (const auto &apartment : apartments) {
        std::cout << "Hotel Name: " << apartment.hotelName << std::endl;
        std::cout << "Type of Apartment: " << apartment.typeOfApartment << std::endl;
        std::cout << "Apartment Number: " << apartment.apartmentNumber << std::endl;
        std::cout << "Number of Rooms: " << apartment.numberOfRooms << std::endl;
        std::cout << "Price: " << apartment.price << std::endl;
        std::cout << "                               " << std::endl;
    }
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
        : Hotel{hotelName,0, "None"}, typeOfApartment{typeOfApartment}, apartmentNumber{apartmentNumber}, numberOfRooms{numberOfRooms}, price{price} {}



//Apartment::Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber, int numberOfRooms, int price)
//    : Hotel{hotelName},typeOfApartment{typeOfApartment},apartmentNumber{apartmentNumber},numberOfRooms{numberOfRooms},price{price}{}
//implemented move constructor
Apartment::Apartment(Apartment &&other) noexcept
    : Hotel{std::move(other)}, typeOfApartment{other.typeOfApartment}, apartmentNumber{other.apartmentNumber}, numberOfRooms{other.numberOfRooms}, price{other.price}{}
Apartment::~Apartment() {std::cout << "Destructor called for apartment: " << this->apartmentNumber << std::endl;}//використання this


