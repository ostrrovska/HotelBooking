
#ifndef RESTAURANTBOOKING_HOTEL_H
#define RESTAURANTBOOKING_HOTEL_H
#include <string>

class Hotel {
public:
    std::string hotelName;
    int numberOfApartments;
    std::string ranking;
    static int numberOfHotels;

    Hotel();
    Hotel(const std::string &name);
    Hotel(const std::string &name, int apartments, const std::string &rank);
    //move constructor
    Hotel(Hotel &&other) noexcept;

    friend std::ostream &operator <<(std::ostream &os, Hotel &other);
    friend std::istream &operator >>(std::istream &is, Hotel &other);


   ~Hotel();

};


#endif //RESTAURANTBOOKING_HOTEL_H
