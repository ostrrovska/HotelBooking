
#ifndef RESTAURANTBOOKING_VIPCUSTOMER_H
#define RESTAURANTBOOKING_VIPCUSTOMER_H
#include "Customer.h"
#include <fstream>

class VIPCustomer final: public Customer {
public:
    std::string vipStatus;
    virtual void writeCustomerToFile(const Customer &customer, std::string &path) override;
    VIPCustomer( std::string &&customerName = "None", int customerID = 0, int age = 0, std::string &&phoneNumber = "None",std::string &&status = "None");
    VIPCustomer(const Customer &customer);
    VIPCustomer(const Customer &customer, const std::string &status);//make the customer VIP
    //implemented copy constructor
    VIPCustomer(const VIPCustomer &other)
            : Customer{other}, vipStatus{other.vipStatus} {}
    virtual ~VIPCustomer();
};


#endif //RESTAURANTBOOKING_VIPCUSTOMER_H
