#pragma once

#include <string>

// TODO : Add < comparator overload and think about compare logic

class Time{
    public:
        Time();
        Time(int _hours,int _minutes);
        int getHours();
        int getMinutes();
        void setHours(int _hours);
        void setMinutes(int _minutes);
        friend std::istream& operator>>(std::istream &is,Time &t);
        std::string c_str();
    private:
        int hours,minutes;
};