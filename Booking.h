#ifndef RESTAURANTBOOKING_BOOKING_H
#define RESTAURANTBOOKING_BOOKING_H
#include <string>
#include "Customer.h"

class Booking {
private:
    Customer customer;
    std::string dateOfArrival;
    std::string dateOfDeparture;
public:
    Booking( const Customer& customer = Customer(), std::string &&dateOfArrival = "None", std::string &&dateOfDeparture = "None");
    ~Booking();
};


#endif //RESTAURANTBOOKING_BOOKING_H
