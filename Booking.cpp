#include "Booking.h"

//move constructor

Booking::Booking(Booking &&other) noexcept
: customer{other.customer}, dateOfArrival{other.dateOfArrival},dateOfDeparture{other.dateOfDeparture}{
    other.customer = nullptr;
    other.dateOfArrival = nullptr;
}
Booking::~Booking() {}