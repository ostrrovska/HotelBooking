#include "Booking.h"

Booking::Booking(Customer customer, std::string &&dateOfArrival, std::string &&dateOfDeparture)
: customer{customer},dateOfArrival{dateOfArrival},dateOfDeparture{std::move(dateOfDeparture)}{}
Booking::~Booking() {}