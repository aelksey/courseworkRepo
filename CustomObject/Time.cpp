#include <string>
#include <sstream>
#include "Time.h"
#include <iostream>

// TODO : Add < comparator overload and think about compare logic

// TODO : Add random data generation

// TODO : Test stuff

// TODO : Add exceptions to constructors and stuff

// TODO : Add << operator overload

Time::Time():hours(0),minutes(0){}

Time::Time(int _hours,int _minutes):hours(_hours),minutes(_minutes){}

int Time::getHours(){return hours;}

int Time::getMinutes(){return minutes;}

void Time::setHours(int _hours){hours = _hours;}

void Time::setMinutes(int _minutes){minutes = _minutes;}

std::istream& operator>>(std::istream &is,Time &t){
    int hours,minutes;
    std::cout << "Введите часы(число): ";
    is >> hours;
    std::cout << std::endl << "Введите минуты(число): ";
    is >> minutes;
    t.setHours(hours);
    t.setMinutes(minutes);
    return is;
}

std::string Time::c_str(){
    std::stringstream ss;
    if (hours / 10 == 0){
        ss << "0" << hours << ":"; 
    }else{ss << hours << ":";}
    if (minutes / 10 == 0){
        ss << "0" << minutes; 
    }else{ss << minutes;}
    return ss.str();
}

