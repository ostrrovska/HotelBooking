
#ifndef RESTAURANTBOOKING_APARTMENT_H
#define RESTAURANTBOOKING_APARTMENT_H
#include <string>

class Apartment {
private:
    std::string hotelName;
    std::string typeOfApartment;
    int apartmentNumber;
    int numberOfRooms;
    int price;
public:
    void getApartmentInfo(); //function to show information about specific apartment
    Apartment();
    Apartment(std::string hotelName);
    Apartment(std::string hotelName, std::string typeOfApartment);
    Apartment(std::string hotelName,std::string typeOfApartment,int apartmentNumber);
    Apartment(std::string hotelName,std::string typeOfApartment,int apartmentNumber,int numberOfRooms);
    Apartment(std::string hotelName,std::string typeOfApartment,int apartmentNumber,int numberOfRooms,int price);
};


#endif //RESTAURANTBOOKING_APARTMENT_H
