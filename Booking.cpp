#include "Booking.h"

Booking::Booking(const Customer& customer, std::string &&dateOfArrival, std::string &&dateOfDeparture)
: customer{customer},dateOfArrival{dateOfArrival},dateOfDeparture{dateOfDeparture}{}
Booking::~Booking() {}