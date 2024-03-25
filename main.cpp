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
    cout<<"Enter who are you: ";
    getline(cin, command);
    vector<Hotel> hotels;
    if(command == "admin"){
    }
    else{
        for(const auto &file: fs::directory_iterator("Hotels")){
            hotels.emplace_back(Hotel::downloadHotelInfo(file.path().filename().string()));

        }
        for (const auto& file : std::filesystem::directory_iterator("Hotels")) {
            if (file.is_directory()) { // Перевіряємо, чи об'єкт є папкою
                std::string filename = file.path().filename().string();
                Hotel hotel = Hotel::downloadHotelInfo(filename);
                hotel.printHotels(hotel);
            }
        }
    }
    return 0;
}
