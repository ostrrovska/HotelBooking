#include "Customer.h"
#include <iostream>

Customer Customer::findCustomerByID(std::vector<Customer> &customers, int customerID) {
    for(int i = 0; i < customers.size(); i++){
        if(customers[i].customerID == customerID)
        {
            return customers[i];
        }
    }
    std::cout << "Invalid ID" << std::endl;
    return {};
}

Customer::Customer(std::string &&customerName, int customerID, int age, std::string &&phoneNumber)
: customerName{customerName},customerID{customerID}, age{age},phoneNumber{phoneNumber}{}
Customer::~Customer(){}
