#include <iostream>
#include "Apartment.h"
#include "Customer.h"
#include "Booking.h"
#include "Hotel.h"
#include "VIPCustomer.h"
#include <filesystem>
#include <memory>
#include <ctime>

namespace fs = std::filesystem;
using namespace std;

bool isStringInteger(string &s) {
    for (auto &c: s) {
        if (!isdigit(c)) return false;
    }
    return true;
}

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
    srand(time(NULL));
    fs::create_directory("Hotels");
    fs::create_directory("Customers");
    try {
        fs::create_directory("Customers/RegularCustomers");
        fs::create_directory("Customers/VipCustomers");
    } catch (const fs::filesystem_error &e) {
        cerr << e.what();
    }
    string command;

    cout << "Please,enter who are you (Admin or Customer): ";
    while (command != "Admin" || command != "Customer") {
        try {
            getline(cin, command);
            if (command != "Admin" && command != "Customer") throw invalid_argument("Invalid user");
            break;
        } catch (const invalid_argument &e) {
            cout << "You entered the user incorrectly. Please, type Admin or Customer" << endl;
        }
    }
    vector<unique_ptr<Hotel>> hotels;
    vector<unique_ptr<Customer>> customers;
    vector<unique_ptr<VIPCustomer>> vipCustomers;
    if (command == "Admin") {
        int password = 1313;
        int passwordToCheck;
        cout << "Please, enter the password: " << endl;
        while (passwordToCheck != password) {
            try {
                cin >> passwordToCheck;
                if (passwordToCheck != password) throw invalid_argument("Invalid password");
                break;
            } catch (const invalid_argument &e) {
                cout << "You entered the password incorrectly. Try again." << endl;
            }
        }
        int adminCommand;
        while (adminCommand != 3) {
            cout << "What do you want to do? " << endl;
            cout << "1 - Add new hotel, 2 - Add new apartment, 3 - exit" << endl;
            cin >> adminCommand;
            if (adminCommand == 1){
                Hotel hotel;
                cout << "-----ADDING NEW HOTEL:----- " << endl;
                cout << "Enter hotel name: " << endl;
                cin.ignore();
                getline(cin, hotel.hotelName);
                cout << "Enter hotel ranking: " << endl;
                getline(cin, hotel.ranking);
                cout << "Enter the information about hotel: " << endl;
                getline(cin, hotel.information);
                cout << "How many apartments should be in your hotel? " << endl;
                int numberOfApartments;
                cin >> numberOfApartments;
                for(int i = 1; i <= numberOfApartments; i++){
                    cout << "-----ADDING APARTMENT #" << i << "-----" << endl;
                    Apartment apartment;
                    cout << "Enter the type of apartment: " << endl;
                    cin.ignore();
                    getline(cin, apartment.typeOfApartment);
                    cout << "Enter the number of apartment: " << endl;
                    cin >> apartment.apartmentNumber;
                    cout << "Enter the number of rooms: " << endl;
                    cin >> apartment.numberOfRooms;
                    cout << "Enter the price of apartment: " << endl;
                    cin >> apartment.price;
                    string path = "Hotels/"+hotel.hotelName+"/";
                    hotel.apartments.emplace_back(apartment);
                    apartment.writeApartmentToFile(path, i);
                }
                fs::create_directory("Hotels/"+hotel.hotelName);
                string path = "Hotels/"+hotel.hotelName+"/";
                hotel.writeHotelToFile(path);
            } else if(adminCommand == 2){
                string hotelName;
                cout << "To which hotel do you want to add new apartment?" << endl;
                getline(cin, hotelName);
                Hotel hotel(Hotel::downloadHotelInfo(hotelName));
                cout << "How many apartments do you want to add? " << endl;
                int numberOfApartments;
                cin >> numberOfApartments;
                for(int i = 1; i <= numberOfApartments; i++){
                    cout << "-----ADDING APARTMENT #" << i << "-----" << endl;
                    Apartment apartment;
                    cout << "Enter the type of apartment: " << endl;
                    cin.ignore();
                    getline(cin, apartment.typeOfApartment);
                    cout << "Enter the number of apartment: " << endl;
                    cin >> apartment.apartmentNumber;
                    cout << "Enter the number of rooms: " << endl;
                    cin >> apartment.numberOfRooms;
                    cout << "Enter the price of apartment: " << endl;
                    cin >> apartment.price;
                    string path = "Hotels/"+hotelName+"/";
                    hotel.apartments.emplace_back(apartment);
                }
                string path = "Hotels/"+hotelName+"/";
                hotel.writeHotelToFile(path);
                cout << "Success! " << "You have added " << numberOfApartments << " apartment/s to" << hotelName << " hotel.";
            }
        }

    } else if (command == "Customer") {
        M:
        std::cout << "Welcome! The following hotels are currently available:" << std::endl;
        while (command != "exit") {
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
            int numberToChoose = 0;
            cin >> numberToChoose;
            while (numberToChoose < 1 || numberToChoose > hotels.size()) {
                cout << "Choose correct number" << endl;
                cin >> numberToChoose;
            }
            Hotel currentHotel = *hotels[numberToChoose - 1];
            currentHotel.printApartments();

            std::cout << "Choose the apartment suitable for your needs: ";
            cin >> numberToChoose;
            while (numberToChoose < 1 || numberToChoose > currentHotel.apartments.size()) {
                cout << "Choose correct number.";
                cin >> numberToChoose;
            }
            cin.ignore();
            Apartment currentApartment = currentHotel.apartments[numberToChoose - 1];
            currentHotel.apartments[numberToChoose - 1].isTaken = true;
            string tempPath = "Hotels/" + currentHotel.hotelName + "/";
            currentHotel.writeHotelToFile(tempPath);
            //Apartment currentApartment = currentHotel.apartments[stoi(command) - 1];
            cout << "Great! You have chosen " << currentApartment.typeOfApartment << " suite " << "in "
                 << currentHotel.hotelName << "! Press 1 to confirm booking or 2 to reselect the hotel" << endl;
            getline(std::cin, command);
            while (command != "1" && command != "2") {
                cout
                        << "You entered the option incorrectly. Please, type 1 to confirm booking or 2 to reselect the hotel "
                        << endl;
                getline(std::cin, command);
            }
            if (stoi(command) == 1) {
                cout << "----------BOOKING CONFIRMATION----------" << endl;
                cout << "Chosen hotel: " << currentHotel.hotelName << endl;
                cout << "Chosen suite: " << currentApartment.typeOfApartment << "(" << currentApartment.price << " GRN"
                     << ")" << endl;
                cout << "Please, fill in the following information: " << endl;
                if (currentApartment.typeOfApartment == "Luxury") {
                    VIPCustomer *vipCustomer = new VIPCustomer();

                    cout << "Your name: ";
                    getline(std::cin, vipCustomer->customerName);
                    cout << "Phone number: ";
                    getline(std::cin, vipCustomer->phoneNumber);
                    cout << "Your age: ";
                    cin >> vipCustomer->age;
                    vipCustomer->customerID = rand() % 1000000 + 100000;
                    if (currentApartment.price >= 3000 && currentApartment.price < 5000) {
                        vipCustomer->vipStatus = "Silver";
                        cout << "Congratulations! Now you are the VIP with silver status!";
                    } else if (currentApartment.price >= 5000 && currentApartment.price < 10000) {
                        vipCustomer->vipStatus = "Gold";
                        cout << "Congratulations! Now you are the VIP with gold status!";
                    } else if (currentApartment.price >= 10000) {
                        vipCustomer->vipStatus = "Diamond";
                        cout << "Congratulations! Now you are the VIP with diamond status!";
                    }
                    vipCustomers.emplace_back(vipCustomer);
                    std::string path = "Customers/VIPCustomers";
                    vipCustomer->writeCustomerToFile(*vipCustomer, path);
                } else {
                    Customer *customer = new Customer();
                    cout << "Your name: ";
                    getline(std::cin, customer->customerName);
                    cout << "Phone number: ";
                    getline(std::cin, customer->phoneNumber);
                    cout << "Your age: ";
                    cin >> customer->age;
                    customer->customerID = rand() % 1000000 + 100000;
                    customers.emplace_back(customer);
                    std::string path = "Customers/RegularCustomers";
                    customer->writeCustomerToFile(*customer, path);
                }
            }
        }
    }
    return 0;
}
