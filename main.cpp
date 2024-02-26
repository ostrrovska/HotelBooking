#include <iostream>
#include "Apartment.h"
#include "Customer.h"
#include "Booking.h"
using namespace std;

void findCustomerByID(std::vector<Customer> &customers, int customerID) {
    bool isFound = false;
    for(int i = 0; i < customers.size(); i++){
        if(customers[i].customerID == customerID)
        {
            isFound = true;
            cout << customers[i].customerName;
        }
    }
    if(!isFound) cout <<"Invalid ID"<<endl;
}

int main() {
    Apartment apartment1("Comfort", 201, 3, 5000);
    Apartment apartment2("Lux",502,6,12000);
    Apartment apartment3("Basic",121,2,2500);
    apartment1.getApartmentInfo();
    apartment2.getApartmentInfo();

    vector<Customer> customers;
    Customer customer1("Katia",100456,18,"+380984563433");
    Customer customer2("Maria",205677,17,"+380675554342");
    Customer customer3("Nazar",690087,18,"+380985674462");
    customers.emplace_back(customer1);
    customers.emplace_back(customer2);
    customers.emplace_back(customer3);

    string idToFind;
    getline(cin,idToFind);
    findCustomerByID(customers, stoi(idToFind));

    Booking booking1(customer1,"13.02.2024","18.02.2024");
    Booking booking2(customer2,"26.02.2024","01.03.2024");
    Booking booking3(customer3,"15.03.2023","20.03.2024");
}
