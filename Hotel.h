
#ifndef RESTAURANTBOOKING_HOTEL_H
#define RESTAURANTBOOKING_HOTEL_H
#include <string>
#include "Description.h"

class Hotel:public Description {
public:
    std::string hotelName;
    int numberOfApartments;
    std::string ranking;
    static int numberOfHotels;
    virtual void displayInfo() const override;
    Hotel();
    Hotel(const std::string &hotelName = "None", int numberOfApartments = 0, const std::string &ranking = "None");
    Hotel(const std::string &hotelName = "None");
    //Hotel(const std::string &name, int apartments, const std::string &rank);
    //move constructor
    Hotel(Hotel &&other) noexcept;
    //copy constructor
    Hotel(const Hotel &other);

    friend std::ostream &operator <<(std::ostream &os, Hotel &other);
    friend std::istream &operator >>(std::istream &is, Hotel &other);

   ~Hotel();

};


#endif //RESTAURANTBOOKING_HOTEL_H
