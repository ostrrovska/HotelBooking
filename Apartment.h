
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
    Apartment(const std::string &hotelName);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment,int apartmentNumber);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment,int apartmentNumber,int numberOfRooms);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment,int apartmentNumber,int numberOfRooms,int price);
    ~Apartment();
};


#endif //RESTAURANTBOOKING_APARTMENT_H
