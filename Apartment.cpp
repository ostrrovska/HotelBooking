#include "Apartment.h"

Apartment::Apartment()
        :{"None","None",0,0,0}{}
Apartment::Apartment(std::string hotelName)
        :{newName, "None",0,0,0}{}
Apartment::Apartment(std::string hotelName, std::string typeOfApartment)
        :{newName, newType, 0,0,0} {}
Apartment::Apartment(std::string hotelName, std::string typeOfApartment,int apartmentNumber){}
        :{newName, newType, newApartmentNumber,0,0} {}
Apartment::Apartment(std::string hotelName, std::string typeOfApartment,int apartmentNumber,int numberOfRooms){}
        :{newName, newType, newApartmentNumber,newNumberOfRooms,0} {}
Apartment::Apartment(std::string hotelName, std::string typeOfApartment,int apartmentNumber,int numberOfRooms, int price){}
        :{newName, newType, newApartmentNumber,newNumberOfRooms,newPrice} {}
