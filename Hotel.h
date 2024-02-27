
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
    Hotel();
    Hotel(const std::string &name, int apartments, const std::string &rank);

    friend std::ostream &operator <<(std::ostream &os, Hotel &other);
    friend std::istream &operator >>(std::istream &is, Hotel &other);

    int showApartments();
   ~Hotel();

};


#endif //RESTAURANTBOOKING_HOTEL_H
