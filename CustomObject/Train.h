#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Time.h"
#include "Station.h"
#include <sstream>

class Train{
    public:
        Train(); // Constructor by default yield object with  randomized parameters
        Train(int _id,std::vector<std::string> _departureDays, Time _departureTime,Time _TimeEnroute,Station _departureStation,Station _arrivalStaion,std::vector<Station> _stations);
        int getId();
        void setId(int _id);
        std::vector<std::string> getDepartureDays();
        void setDepartureDays(std::vector<std::string> _departureDays);
        Time getDepartureTime();
        void setDepartureTime(Time _departureTime);
        Time getTimeEnroute();
        void setTimeEnroute(Time _TimeEnroute);
        Station getDepartureStation();
        void setDepartureStation(Station _departureStation);
        Station getArrivalStaion();
        void setArrivalStaion(Station _arrivalStaion);
        std::vector<Station> getStations();
        void setStations(std::vector<Station> _stations);
        // Less than operator overload
        bool operator<(const Train &t) const;
        friend std::ostream& operator<<(std::ostream &os,Train &t);
        friend std::ostream& operator<<(std::stringstream &ss,Train &t);
        friend std::istream& operator>>(std::istream &is,Train &t);
        std::string c_str();
    private:
        int id;
        std::vector<std::string> departureDays;
        Time departureTime;
        Time TimeEnroute;
        Station departureStation;
        Station arrivalStaion;
        std::vector<Station> stations;
};