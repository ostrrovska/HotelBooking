#include "Booking.h"

//move constructor
Booking::Booking(const Customer& customer, std::string &&dateOfArrival, std::string &&dateOfDeparture) noexcept
        : customer{customer}, dateOfArrival{std::move(dateOfArrival)}, dateOfDeparture{std::move(dateOfDeparture)} {
//занулення вказівників?
}
Booking::~Booking() {}