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
        std::vector<std::string> STATION_NAMES = {"�����������","�����������-��������","�����������-�������","�����������-�����","���-2","������������","������","������","�����","����","�����-���������","�����","����","�������","�����������","������������","�����������-��-�����","����������","�����������","������-��-����","���������","�����������","��������","������","����������","�����","���������","����������-�����","������������","�����","���������","�����������","�����������","����������","����������","�����������","�������","�����������","�����"};
        std::vector<std::string> DAYS = {"��","��","��","��","��","��","��"};
};