//
// Created by ACER on 21.02.2024.
//

#ifndef RESTAURANTBOOKING_CUSTOMER_H
#define RESTAURANTBOOKING_CUSTOMER_H
#include <string>
#include <vector>

class Customer {
private:
    int age;
    std::string phoneNumber;
public:
    std::string customerName;
    int customerID;
    Customer(std::string &&customerName = "None", int customerID = 0, int age = 0, std::string &&phoneNumber = "None"); //constructor by default
    //конструктор копіювання
    Customer(const Customer &other);
    ~Customer();


};



#endif //RESTAURANTBOOKING_CUSTOMER_H
