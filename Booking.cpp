#include "Booking.h"

//move constructor

Booking::Booking() {}
Booking::Booking(Customer *customer, const std::string &dateOfArrival, const std::string &dateOfDeparture)
:customer{customer}, dateOfArrival{dateOfArrival}, dateOfDeparture{dateOfDeparture}{}
Booking::Booking(Booking &&other) noexcept
: customer{other.customer}, dateOfArrival{other.dateOfArrival},dateOfDeparture{other.dateOfDeparture}{
    other.customer = nullptr;
}
Booking::~Booking() {
    if (customer != nullptr) {
        delete customer;
    }
}