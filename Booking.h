#ifndef RESTAURANTBOOKING_BOOKING_H
#define RESTAURANTBOOKING_BOOKING_H
#include <string>
#include "Customer.h"

class Booking {
private:
    Customer *customer;
    std::string *dateOfArrival;
    std::string *dateOfDeparture;
public:
    //move constructor
    Booking(Booking &&other) noexcept;
    ~Booking();
};


#endif //RESTAURANTBOOKING_BOOKING_H
