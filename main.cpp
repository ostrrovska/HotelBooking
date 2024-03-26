#include <iostream>
#include "Apartment.h"
#include "Customer.h"
#include "Booking.h"
#include "Hotel.h"
#include "VIPCustomer.h"
#include <filesystem>
namespace fs = std::filesystem;
using namespace std;

void findCustomerByID(std::vector<Customer> &customers, int customerID) {
    bool isFound = false;
    for(int i = 0; i < customers.size(); i++){
        if(customers[i].customerID == customerID)
        {
            isFound = true;
            cout << customers[i].customerName;
            break;
        }
    }
    if(!isFound) cout <<"Invalid ID"<<endl;
}
int main() {
    fs::create_directory("Hotels");
    string command;
    cout<<"Please,enter who are you: ";
    getline(cin, command);
    vector<unique_ptr<Hotel>> hotels;
    if(command == "admin"){
    }
    else{
        std::cout << "Welcome! The following hotels are currently available:" << std::endl;
        std::cout << "--------------------------------------------------------------"<<std::endl;
        for(const auto &file: fs::directory_iterator("Hotels")){
            hotels.emplace_back(std::unique_ptr<Hotel>(new Hotel(Hotel::downloadHotelInfo(file.path().filename().string()))));
        }
        int i = 1;
        for (const auto& file : std::filesystem::directory_iterator("Hotels")) {
            std::cout << i << ".";
            //Hotel::printHotels(Hotel::downloadHotelInfo(file.path().filename().string()));
            hotels[i-1]->printHotel();
            hotels[i-1]->printApartments();
            i++;
        }

    }
    return 0;
}
