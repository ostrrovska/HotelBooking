
#ifndef RESTAURANTBOOKING_HOTEL_H
#define RESTAURANTBOOKING_HOTEL_H
#include <string>
#include <vector>
#include "Description.h"
#include "Apartment.h"


class Hotel:public Description {
public:
    std::string hotelName;
    int numberOfApartments;
    std::string ranking;
    std::string information;
    static int numberOfHotels;
    std::vector<Apartment> apartments;
    virtual void displayInfo() const override;
    static Hotel downloadHotelInfo(const std::string &filename);
    Hotel();
    Hotel(const std::string &hotelName, int numberOfApartments, const std::string &ranking);
    //Hotel(const std::string &name, int apartments, const std::string &rank);
    //move constructor
    Hotel(Hotel &&other) noexcept;
    //copy constructor
    Hotel(const Hotel &other);

    friend std::ostream &operator <<(std::ostream &os, Hotel &other);
    friend std::istream &operator >>(std::istream &is, Hotel &other);

   virtual ~Hotel();

};


#endif //RESTAURANTBOOKING_HOTEL_H
