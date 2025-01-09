#include "Random.h"
#include <experimental/random>
#include <vector>
#include "../CustomObject/Time.h"
#include "../CustomObject/Station.h"
#include "../CustomObject/Train.h"

Random::Random(){}

int Random::randInt(int lb,int rb){
    return std::experimental::randint(lb,rb);
}

Time Random::randTime(){
    int hours = randInt(0,24);
    int minutes = randInt(0,60);
    return Time(hours,minutes);
}

Station Random::randStation(){
    int id = randInt(0,9999);
    std::string name = STATION_NAMES[randInt(0,STATION_NAMES.size()-1)];
    return Station(id,name);
}

std::vector<Station> Random::randStations(){
    std::vector<Station> tempVec;
    int vecSize = randInt(0,20);
    for(int i = 0;i < vecSize;i++) tempVec.push_back(randStation());
    return tempVec;
}

std::vector<std::string> Random::randDays(){
    std::vector<std::string> tempVec;
    int vecSize = randInt(1,6);
    for(int i = 0; i < vecSize;i++) tempVec.push_back(DAYS[i]);
    return tempVec;
}

Train Random::randTrain(){
    int id = randInt(0,9999);
    std::vector<std::string> departureDays = randDays();
    Time departureTime = randTime();
    Time TimeEnroute = randTime();
    Station departureStation = randStation();
    Station arrivalStaion = randStation();
    std::vector<Station> stations = randStations();
    return Train(id,departureDays,departureTime,TimeEnroute,departureStation,arrivalStaion,stations);
}