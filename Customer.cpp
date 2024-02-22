#include "Customer.h"
#include <iostream>

int Customer::getID() {
    return customerID;
}
std::string Customer::getName() {
    return customerName;
}
Customer::Customer(std::string &&customerName, int customerID, int age, std::string &&phoneNumber)
: customerName{customerName},customerID{customerID}, age{age},phoneNumber{phoneNumber}{}
Customer::~Customer(){}
