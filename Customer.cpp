#include "Customer.h"

Customer::Customer(std::string &&customerName, int customerID, int age, std::string &&phoneNumber)
    : customerName{customerName},customerID{customerID}, age{age},phoneNumber{phoneNumber}{}
