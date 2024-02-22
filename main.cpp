#include <iostream>
#include "Apartment.h"
#include "Customer.h"
#include "Booking.h"
using namespace std;


int main() {

    Apartment apartment1("Comfort", 201, 3, 5000);
    Apartment apartment2("Lux",502,6,12000);
    Apartment apartment3("Basic",121,2,2500);

    vector<Customer> customers;
    Customer customer1("Katia",100456,18,"+380984563433");
    Customer customer2("Maria",205677,17,"+380675554342");
    Customer customer3("Nazar",690087,18,"+380985674462");


}
