//
// Created by ACER on 21.02.2024.
//

#ifndef RESTAURANTBOOKING_CUSTOMER_H
#define RESTAURANTBOOKING_CUSTOMER_H
#include <string>

class Customer {
private:
    std::string customerName;
    int customerID;
    int age;
    std::string phoneNumber;
public:
    Customer(std::string &&customerName = "None", int customerID = 0, int age = 0, std::string &&phoneNumber = "None"); //constructor by default
};



#endif //RESTAURANTBOOKING_CUSTOMER_H
