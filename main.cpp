#include <iostream>
#include "Apartment.h"
#include "Customer.h"
#include "Booking.h"
#include "Hotel.h"
#include "VIPCustomer.h"
#include <filesystem>
#include <memory>
#include <random>

namespace fs = std::filesystem;
using namespace std;

void findCustomerByID(std::vector<Customer> &customers, int customerID) {
    bool isFound = false;
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].customerID == customerID) {
            isFound = true;
            cout << customers[i].customerName;
            break;
        }
    }
    if (!isFound) cout << "Invalid ID" << endl;
}

int main() {
    fs::create_directory("Hotels");
    fs::create_directory("Customers");
    try {
        fs::create_directory("Customers/RegularCustomers");
        fs::create_directory("Customers/VipCustomers");
    } catch (const fs::filesystem_error &e) {
        cerr << e.what();
    }
    string command;
    cout << "Please,enter who are you: ";
    getline(cin, command);
    vector<unique_ptr<Hotel>> hotels;
    vector<unique_ptr<Customer>> customers;
    if (command == "admin") {
    } else {
        M:
        std::cout << "Welcome! The following hotels are currently available:" << std::endl;
        for (const auto &file: fs::directory_iterator("Hotels")) {
            hotels.emplace_back(std::make_unique<Hotel>(Hotel::downloadHotelInfo(file.path().filename().string())));
        }
        int i = 1;
        for (const auto &file: fs::directory_iterator("Hotels")) {
            std::cout << "---------------------------------------------------------------" << std::endl;
            std::cout << i << ".";
            hotels[i - 1]->printHotel();
            i++;
        }
        std::cout << std::endl;
        std::cout << "Please, enter the number of the hotel you would like to choose: ";
        getline(std::cin, command);
        Hotel currentHotel = *hotels[std::stoi(command) - 1];
        currentHotel.printApartments();
        std::cout << "Choose the apartment suitable for your needs: ";
        getline(std::cin, command);
        Apartment currentApartment = currentHotel.apartments[stoi(command) - 1];
        cout << "Great! You have chosen " << currentApartment.typeOfApartment << " suite " << "in "
             << currentHotel.hotelName << "! Press 1 to confirm booking or 2 to reselect the hotel" << endl;
        getline(std::cin, command);
        if( stoi(command) == 1){
            cout << "----------BOOKING CONFIRMATION----------" << endl;
            cout << "Chosen hotel: " << currentHotel.hotelName << endl;
            cout << "Chosen suite: " << currentApartment.typeOfApartment <<"("<<currentApartment.price << " GRN" << ")" << endl;
            cout << "Please, fill in the following information: " << endl;
            Customer customer;
            cout << "Your name: ";
            getline(std::cin, customer.customerName);
            cout << "Phone number: ";
            getline(std::cin, customer.phoneNumber);
            cout << "Your age: ";
            cin >> customer.age;
        }
        else{
            goto M;
        }


    }
    return 0;
}
