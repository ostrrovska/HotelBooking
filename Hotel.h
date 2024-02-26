//
// Created by ACER on 26.02.2024.
//

#ifndef RESTAURANTBOOKING_HOTEL_H
#define RESTAURANTBOOKING_HOTEL_H
#include <string>

class Hotel {
private:
    std::string hotelName;
    int numberOfApartments;
    std::string ranking;
public:
    static int numberOfHotels;
    //оголошення конструктору
    Hotel();
    Hotel(const std::string &name, int apartments, const std::string &rank);
   ~Hotel();
    int showApartments();

};


#endif //RESTAURANTBOOKING_HOTEL_H
