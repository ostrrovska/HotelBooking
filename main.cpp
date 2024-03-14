#include <iostream>
#include "Apartment.h"
#include "Customer.h"
#include "Booking.h"
#include "Hotel.h"
#include "VIPCustomer.h"
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
    vector <Apartment> apartments;
    Apartment apartment1("Hotel1","Comfort",1009,3,400);
    Apartment apartment2("hotel1","Lux",2013,5,1000);
    Apartment apartment3("Hotel2","Lux",2014,6,900);
    apartments.emplace_back ("Hotel1", "Comfort", 1009, 3, 400);
    apartments.emplace_back ("Hotel2", "Lux", 2013, 5, 1000);
    Apartment::showApartments(apartments);

    //apartments.emplace_back(apartment1);
//    apartment1.getApartmentInfo();
//    apartment2.getApartmentInfo();
//    apartment3.getApartmentInfo();

    vector<Customer> customers;
    Customer customer1("Katia",100456,18,"+380984563433");
    Customer customer2("Maria",205677,17,"+380675554342");
    Customer customer3("Nazar",690087,18,"+380985674462");
    VIPCustomer customer4("Olha",468900,20,"+380675554728","Gold");
    VIPCustomer customer5(customer1);
    VIPCustomer customer6(customer1, "Silver");

    customers.emplace_back(customer1);
    customers.emplace_back(customer2);
    customers.emplace_back(customer3);
    customers.emplace_back(customer4);

    string idToFind;
    getline(cin,idToFind);
    findCustomerByID(customers, stoi(idToFind));

    Booking booking1(&customer1,"13.02.2024","18.02.2024");
    Booking booking2(&customer2,"26.02.2024","01.03.2024");
    Booking booking3(&customer3,"15.03.2023","20.03.2024");



    return 0;
}
