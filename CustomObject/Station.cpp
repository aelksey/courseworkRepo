#include <string>
#include <sstream>
#include "Station.h"
#include <iostream>

// TODO : Add < comparator overload and think about compare logic

// TODO : Add random data generation

// TODO : Test stuff

Station::Station():id(0),name(){}

Station::Station(int _id, std::string _name):id(_id),name(_name){}

int Station::getId(){return id;}

std::string Station::getName(){return name;}

void Station::setId(int _id){id = _id;}

void Station::setName(std::string _name){name = _name;}

std::istream& operator>>(std::istream &is,Station &s){
    int id;
    std::string name;
    std::cout << "Введите номер станции(число): ";
    std::cin >> id;
    std::cout << std::endl << "Введите название станции: ";
    std::cin >> name;
    s.setId(id);
    s.setName(name);
    return is;
}

std::string Station::c_str(){
    std::stringstream ss;
    ss << name;
    return ss.str();
}