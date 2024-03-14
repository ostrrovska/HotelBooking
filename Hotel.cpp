
#include "Hotel.h"
#include <iostream>
int Hotel::numberOfHotels = 0;

Hotel::Hotel()
: Hotel{"None", 0, "None"}{
    numberOfHotels++;
}
//Hotel::Hotel(const std::string &name, int apartments, const std::string &rank)
//    : hotelName{name},numberOfApartments{apartments},ranking{rank} {
//    numberOfHotels++;
//}
Hotel::Hotel(const std::string &hotelName, int numberOfApartments, const std::string &ranking)
    :hotelName{hotelName},numberOfApartments{numberOfApartments},ranking{ranking} {
    numberOfHotels++;
}
Hotel::Hotel(const std::string &hotelName)
: hotelName{hotelName}{
    numberOfHotels++;
}
//move constructor
Hotel::Hotel(Hotel &&other) noexcept
    : hotelName{other.hotelName},numberOfApartments{other.numberOfApartments},ranking{other.ranking}{}
//copy constructor
Hotel::Hotel(const Hotel &other)
    : hotelName{other.hotelName},numberOfApartments{other.numberOfApartments},ranking(other.ranking){}

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

int Hotel::showApartments() {

}
