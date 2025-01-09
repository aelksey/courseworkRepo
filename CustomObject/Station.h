#pragma once

#include <string>

// TODO : Add < comparator overload and think about compare logic

// TODO : Add random data generation

class Station{
    public:
        Station();
        Station(int _id, std::string _name);
        int getId();
        std::string getName();
        void setId(int _id);
        void setName(std::string _name);
        friend std::istream& operator>>(std::istream &is,Station &s);
        std::string c_str();
    private:
        int id;
        std::string name;
};