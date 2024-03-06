
#ifndef RESTAURANTBOOKING_VIPCUSTOMER_H
#define RESTAURANTBOOKING_VIPCUSTOMER_H
#include "Customer.h"

class VIPCustomer: public Customer {
public:
    std::string vipStatus;
};


#endif //RESTAURANTBOOKING_VIPCUSTOMER_H
