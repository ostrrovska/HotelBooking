//
// Created by ACER on 26.02.2024.
//

#ifndef RESTAURANTBOOKING_HOTEL_H
#define RESTAURANTBOOKING_HOTEL_H
#include <string>

class Hotel {
public:
    std::string hotelName;
    int numberOfApartments;
    std::string ranking;
private:
    int showApartments();

};


#endif //RESTAURANTBOOKING_HOTEL_H
