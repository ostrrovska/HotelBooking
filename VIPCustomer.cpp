
#include "VIPCustomer.h"

VIPCustomer::VIPCustomer(std::string &&customerName, int customerID, int age, std::string &&phoneNumber, std::string &&status)
        : Customer(std::move(customerName), customerID, age, std::move(phoneNumber)), vipStatus(std::move(status)) {}
VIPCustomer::~VIPCustomer(){}
