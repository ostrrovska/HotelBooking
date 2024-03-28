//
// Created by ACER on 21.02.2024.
//

#ifndef RESTAURANTBOOKING_CUSTOMER_H
#define RESTAURANTBOOKING_CUSTOMER_H
#include <string>
#include <vector>

class Customer {
public:
    std::string customerName;
    int age;
    std::string phoneNumber;
    int customerID;
    virtual void writeCustomerToFile(const Customer &customer, std::string &path);
    //constructor by default
    Customer(const std::string &customerName = "None", int customerID = 0, int age = 0, const std::string &phoneNumber = "None");
    //copy constructor
    Customer(const Customer &other);
//    static Customer downloadCustomerInfo(const std::string &filename);
    virtual ~Customer();
};



#endif //RESTAURANTBOOKING_CUSTOMER_H
