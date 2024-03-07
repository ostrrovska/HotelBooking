
#ifndef RESTAURANTBOOKING_VIPCUSTOMER_H
#define RESTAURANTBOOKING_VIPCUSTOMER_H
#include "Customer.h"

class VIPCustomer: public Customer {
public:
    std::string vipStatus;
    VIPCustomer( std::string &&customerName = "None", int customerID = 0, int age = 0, std::string &&phoneNumber = "None",std::string &&status = "None");
    VIPCustomer(const Customer &customer);
    VIPCustomer(const Customer &customer, const std::string &status);//make the customer VIP
    //implemented copy constructor
    VIPCustomer(const VIPCustomer &other)
            : Customer{other}, vipStatus{other.vipStatus} {}
    ~VIPCustomer();
};


#endif //RESTAURANTBOOKING_VIPCUSTOMER_H
