
#ifndef RESTAURANTBOOKING_APARTMENT_H
#define RESTAURANTBOOKING_APARTMENT_H
#include <string>
#include "Hotel.h"
#include <vector>

class Apartment: public Hotel{
public:
    std::string typeOfApartment;
    int apartmentNumber;
    int numberOfRooms;
    int price;
    void getApartmentInfo(); //function to show information about specific apartment
    Apartment();
    Apartment(const std::string &hotelName);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment,int apartmentNumber);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment,int apartmentNumber,int numberOfRooms);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment,int apartmentNumber,int numberOfRooms,int price);
    //Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber, int numberOfRooms, int price);
    //implemented move constructor
    Apartment(Apartment &&other) noexcept;
    void static showApartments(std::vector<Apartment> &apartments);//function to show all apartments
    ~Apartment();


};


#endif //RESTAURANTBOOKING_APARTMENT_H
