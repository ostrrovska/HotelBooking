#include "Customer.h"
#include <iostream>

/*void findCustomerByID(std::vector<Customer> &customers, int customerID) {
    bool isFound = false;
    for(int i = 0; i < customers.size(); i++){
        if(customers[i].customerID == customerID)
        {
            isFound = true;
            std::cout << customers[i].customerName;
        }
    }
    if(!isFound) std::cout <<"Invalid ID"<<std::endl;
}*/

Customer::Customer(std::string &&customerName, int customerID, int age, std::string &&phoneNumber)
: customerName{customerName},customerID{customerID}, age{age},phoneNumber{phoneNumber}{}
Customer::~Customer(){}
