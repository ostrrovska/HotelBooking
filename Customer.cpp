#include "Customer.h"
#include <iostream>

//constructor with default
Customer::Customer(std::string &&customerName, int customerID, int age, std::string &&phoneNumber)
: customerName{customerName},customerID{customerID}, age{age},phoneNumber{phoneNumber}{}

//copy constructor
Customer::Customer(const Customer &other)
        : age{other.age}, phoneNumber{other.phoneNumber}, customerName{other.customerName}, customerID{other.customerID} {}
Customer::~Customer(){}