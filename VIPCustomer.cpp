
#include "VIPCustomer.h"

VIPCustomer::VIPCustomer(std::string &&customerName, int customerID, int age, std::string &&phoneNumber, std::string &&status)
    : Customer{customerName, customerID, age, phoneNumber}, vipStatus{status} {}
VIPCustomer::VIPCustomer(const Customer &customer)
    : VIPCustomer{customer, "Silver"}{}
VIPCustomer::VIPCustomer(const Customer &customer, const std::string &status)
    : Customer{customer},vipStatus{status}{}
VIPCustomer::~VIPCustomer(){}
