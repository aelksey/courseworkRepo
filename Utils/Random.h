#pragma once

#include <experimental/random>
#include <vector>
#include "../CustomObject/Time.h"
#include "../CustomObject/Station.h"
#include "../CustomObject/Train.h"

class Random{
    public:
        Random();
        int randInt(int lb,int rb);
        Time randTime();
        Station randStation();
        std::vector<Station> randStations();
        std::vector<std::string> randDays();
        Train randTrain();
    private:
        std::vector<std::string> STATION_NAMES = {"Новокузнецк","Новосибирск-Западный","Новосибирск-Главный","Новосибирск-Южный","Объ-2","Новошахтинск","Москва","Самара","Пермь","Тула","Санкт-Петербург","Томск","Омск","Иркутск","Владивосток","Благовещенск","Комсомольск-на-Амуре","Вологоград","Калининград","Ростов-на-Дону","Хабаровск","Прокопьевск","Киселёвск","Белово","Биробиджан","Топки","Челябинск","Набережные-Челны","Междуреченск","Киров","Краснодар","Севастополь","Симферополь","Красностав","Черногорск","Зеленогорск","Грозный","Владикавказ","Адлер"};
        std::vector<std::string> DAYS = {"Пн","Вт","Ср","Чт","Пт","Сб","Вс"};
};