#include "Customer.h"
#include <iostream>
#include <filesystem>
#include <fstream>

//Customer Customer::downloadCustomerInfo(const std::string &filename) {
//    std::string path = "Customers/"+filename+"/";
//}
void Customer::writeCustomerToFile(const Customer &customer, std::string &path) {
    //std::string path1 = "Customers/RegularCustomers";
    std::ofstream writeToFile(path + "/Customer" + std::to_string(customer.customerID) + ".txt");//id as a name
        writeToFile << "Name: " << customer.customerName << std::endl;
        writeToFile << "Phone number: " << customer.phoneNumber << std::endl;
        writeToFile << "Age: " << customer.age << std::endl;
        writeToFile.close();
}

//constructor with default
Customer::Customer(const std::string &customerName, int customerID, int age, const std::string &phoneNumber)
        : customerName{customerName}, customerID{customerID}, age{age}, phoneNumber{phoneNumber} {}

//copy constructor
Customer::Customer(const Customer &other)
        : age{other.age}, phoneNumber{other.phoneNumber}, customerName{other.customerName},
          customerID{other.customerID} {}

Customer::~Customer() {}