#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "Time.h"
#include "Station.h"
#include "Train.h"
#include "../Utils/Random.h"

Train::Train(){ // Constructor by default yield object with  randomized parameters
    Random r;
    id = r.randInt(0,9999);
    departureDays = r.randDays();
    departureTime = r.randTime();
    TimeEnroute = r.randTime();
    departureStation = r.randStation();
    arrivalStaion = r.randStation();
    stations = r.randStations();
}

Train::Train(int _id,std::vector<std::string> _departureDays, Time _departureTime,Time _TimeEnroute,Station _departureStation,Station _arrivalStaion,std::vector<Station> _stations){
    id = _id;
    departureDays = _departureDays;
    departureTime = _departureTime;
    TimeEnroute = _TimeEnroute;
    departureStation = _departureStation;
    arrivalStaion = _arrivalStaion;
    stations = _stations;
}

// Acessors & mutators

int Train::getId(){return id;}

void Train::setId(int _id){id = _id;}

std::vector<std::string> Train::getDepartureDays(){return departureDays;}

void Train::setDepartureDays(std::vector<std::string> _departureDays){departureDays = _departureDays;}

Time Train::getDepartureTime(){return departureTime;}

void Train::setDepartureTime(Time _departureTime){departureTime = _departureTime;}

Time Train::getTimeEnroute(){return TimeEnroute;}

void Train::setTimeEnroute(Time _TimeEnroute){TimeEnroute = _TimeEnroute;}

Station Train::getDepartureStation(){return departureStation;}

void Train::setDepartureStation(Station _departureStation){departureStation = _departureStation;}

Station Train::getArrivalStaion(){return arrivalStaion;}

void Train::setArrivalStaion(Station _arrivalStaion){arrivalStaion = _arrivalStaion;}

std::vector<Station> Train::getStations(){return stations;}

void Train::setStations(std::vector<Station> _stations){stations = _stations;}

// Less than operator overload for correct sorting functionality

bool Train::operator<(const Train &t)const{
    return id < t.id ? true : false;
}

std::ostream& operator<<(std::ostream &os,Train &t){
    os << t.c_str();
    return os;
}

std::ostream& operator<<(std::stringstream &ss,Train &t){
    ss << t.c_str();
    return ss;
}

std::istream& operator>>(std::istream &is,Train &t){
    int id,vecSize,vecStationsSize;
    Time departureTime,TimeEnroute;
    Station departureStation,arrivalStation;
    std::cout << "Введите номер поезда(число): ";
    std::cin >> id;
    std::cout << std::endl << "Введите число дней,в которые отправляется поезд(число): ";
    std::cin >> vecSize;
    std::vector<std::string> departureDays(vecSize);
    std::cout << std::endl << "Введите дни недели, в которые идёт поезд(строки производной длины через пробел):";
    for(int i = 0;i < departureDays.size();i++)std::cin >> departureDays[i];
    std::cout << std::endl << "Введите время отправления: ";
    std::cin >> departureTime;
    std::cout << std::endl << "Введите время в пути";
    std::cin >> TimeEnroute;
    std::cout << std::endl << "Введите станцию отправления: ";
    std::cin >> departureStation;
    std::cout << std::endl << "Введите станцию прибытия: ";
    std::cin >> arrivalStation;
    std::cout << std::endl << "Введите число промежуточных станций: ";
    std::cin >> vecStationsSize;
    std::vector<Station> stations(vecStationsSize);
    std::cout << std::endl << "Введите промежуточные станции:";
    for(int i = 0;i < stations.size();i++)std::cin >> stations[i];
    t.setId(id);
    t.setDepartureDays(departureDays);
    t.setDepartureTime(departureTime);
    t.setTimeEnroute(TimeEnroute);
    t.setDepartureStation(departureStation);
    t.setArrivalStaion(arrivalStation);
    t.setStations(stations);
    return is;
}

std::string Train::c_str(){
    std::stringstream ss;
    ss << "Номер поезда: " << id << std::endl; 
    ss << "Дни недели отправления: ";
    for(int i = 0;i < departureDays.size();i++)ss << departureDays[i] << " ";
    ss << std::endl;
    ss << "Время отправления: " << departureTime.c_str() << std::endl;
    ss << "Время в пути: " << TimeEnroute.c_str() << std::endl;
    ss << "Станция отправления: " << departureStation.c_str() << std::endl;
    ss << "Станция прибытия: " << arrivalStaion.c_str() << std::endl;
    ss << "Промежуточные станции: ";
    for(int i = 0;i < stations.size();i++)ss << stations[i].c_str() << " ";
    ss << std::endl;
    return ss.str();
}

