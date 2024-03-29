
#ifndef RESTAURANTBOOKING_APARTMENT_H
#define RESTAURANTBOOKING_APARTMENT_H
#include <string>
#include <vector>
#include "Description.h"
#include "Customer.h"

class Apartment: public Description{
public:
    Customer customer;
    std::string typeOfApartment;
    int apartmentNumber;
    int numberOfRooms;
    int price;
    bool isTaken;

    virtual void displayInfo() const override;
    void writeApartmentToFile(std::string &path, int index);
    static Apartment downloadApartmentInfo(const std::string &filename, const std::string &path);
    //void static showApartments(std::vector<Apartment> &apartments);//function to show all apartments
    //void getApartmentInfo(); //function to show information about specific apartment
    Apartment();
    Apartment(const std::string &hotelName);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment,int apartmentNumber);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment,int apartmentNumber,int numberOfRooms);
    Apartment(const std::string &hotelName, const std::string &typeOfApartment,int apartmentNumber,int numberOfRooms,int price);
    //Apartment(const std::string &hotelName, const std::string &typeOfApartment, int apartmentNumber, int numberOfRooms, int price);
    //implemented move constructor
    Apartment(Apartment &&other) noexcept;
    Apartment(const Apartment &apartment);
    ~Apartment();


};


#endif //RESTAURANTBOOKING_APARTMENT_H
