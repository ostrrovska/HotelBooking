#include <iostream>
#include "VIPCustomer.h"
void VIPCustomer::writeCustomerToFile(const Customer &customer, std::string &path) {
    Customer::writeCustomerToFile(customer, path);
    std::string filename = path + "/Customer" + std::to_string(customerID) + ".txt";
    std::ofstream fileToWrite(filename, std::ios_base::app);
    fileToWrite << "VIP Status: " << vipStatus << std::endl;
    fileToWrite.close();
}
VIPCustomer::VIPCustomer(std::string &&customerName, int customerID, int age, std::string &&phoneNumber, std::string &&status)
    : Customer{customerName, customerID, age, phoneNumber}, vipStatus{status} {}
VIPCustomer::VIPCustomer(const Customer &customer)
    : VIPCustomer{customer, "Silver"}{} //default VIP status
VIPCustomer::VIPCustomer(const Customer &customer, const std::string &status)
    : Customer{customer},vipStatus{status}{} //non-defalt VIP status
VIPCustomer::~VIPCustomer(){}
