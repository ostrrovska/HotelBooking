#include "Hotel.h"
#include "Apartment.h"
#include <iostream>
#include <fstream>
#include <filesystem>

int Hotel::numberOfHotels = 0;

void Hotel::displayInfo() const {
    std::cout << "Hotel name: "<< hotelName << std::endl;
    std::cout << "Number of apartments: " << numberOfApartments << std::endl;
    std::cout << "Ranking" << ranking << std::endl;
}
void Hotel::writeHotelToFile(std::string &path) {
    std::ofstream writeToFile(path + hotelName + ".txt", std::ostream::out);
    for(int i = 0; i < apartments.size(); i++){
        apartments[i].writeApartmentToFile(path, i);
    }
    writeToFile << hotelName << std::endl;
    writeToFile << ranking<< std::endl;
    writeToFile << information << std::endl;
    writeToFile.close();
}
Hotel Hotel::downloadHotelInfo(const std::string &filename) {
    std::string path = "Hotels/"+filename+"/";
    Hotel hotel;
    for(const auto &file : std::filesystem::directory_iterator("Hotels/"+filename)){
        if(file.path().filename().string() != filename+".txt"){// check if not hotel
            hotel.apartments.emplace_back(Apartment::downloadApartmentInfo(file.path().filename().string(),path));
        }
    }
    std::ifstream fileToRead(path+filename+".txt", std::ifstream::out); //open
    std::string currentLine;
    getline(fileToRead, currentLine);
    hotel.hotelName = currentLine;
    getline(fileToRead, currentLine);
    hotel.ranking = currentLine;
    while(!fileToRead.eof()){
        getline(fileToRead, currentLine);
        hotel.information += currentLine;
    }
    fileToRead.close();
    return hotel;
}
void Hotel::printHotel() {
    std::cout << "Name: " << hotelName << std::endl;
    std::cout << "Ranking: " << ranking << std::endl;
    std::cout << "Information: " << information << std::endl;
}
void Hotel::printApartments() {
    int i = 1;
    for(Apartment &a : apartments)
    {
        if(!a.isTaken){
            std::cout << i << ".";
            a.displayInfo();
            std::cout << std::endl;
            i++;
        }
    }
}
Hotel::Hotel()
: Hotel{"None", 0, "None"}{
    numberOfHotels++;
}
//Hotel::Hotel(const std::string &name, int apartments, const std::string &rank)
//    : hotelName{name},numberOfApartments{apartments},ranking{rank} {
//    numberOfHotels++;
//}
Hotel::Hotel(const std::string &hotelName, int numberOfApartments, const std::string &ranking)
    :hotelName{hotelName},numberOfApartments{numberOfApartments},ranking{ranking},information{""},apartments{} {
    numberOfHotels++;
}
//move constructor
Hotel::Hotel(Hotel &&other) noexcept
    : hotelName{other.hotelName},numberOfApartments{other.numberOfApartments},ranking{other.ranking},
    information{other.information}, apartments{other.apartments}{
}
//copy constructor
Hotel::Hotel(const Hotel &other)
    : hotelName{other.hotelName},numberOfApartments{other.numberOfApartments},ranking{other.ranking},
    information{other.information},apartments{other.apartments}{
    numberOfHotels++;
}

std::ostream &operator <<(std::ostream &os, Hotel &other) {
    os << "Hotel name: " << other.hotelName << std::endl
       << "Number of apartments: " << other.numberOfApartments << std::endl
       << "Ranking: " << other.ranking << std::endl;
    return os;
};
std::istream &operator >> (std::istream &is, Hotel &other){
    std::cout << "Enter the name of the hotel: " << std::endl;
    is >> other.hotelName;
    std::cout << "Enter the number of apartments: " << std::endl;
    is >> other.numberOfApartments;
    std::cout << "Enter ranking: " << std::endl;
    is >> other.ranking;
    return is;
}
 Hotel::~Hotel() {
    numberOfHotels--;
}


