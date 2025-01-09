#pragma once
#include <string>
#include "../CustomObject/Train.h"
#include "../LinkedList.h"

class Driver{
    public:
        Driver();
        void Start();
        void showAbout();
        void askMode();
        void askType();
        void showMenu();
        void showMenuStandart();
        void showMenuTimeComplexity();
        void timeComplexityAdd();
        void timeComplexityRemove();
        void timeComplexitySort();
        void timeComplexitySearch();
        void timeComplexityFull();
        void calculateTimeComplexityAdd(int n);
        void calculateTimeComplexityRemove(int n);
        void calculateTimeComplexitySearch(int n);
        void calculateTimeComplexitySort(int n);
        void ClearNoEcho();
        void showOperationsPrimitive();
        void showOperationsCustomObj();
        void Add();
        void Delete();
        void Search();
        void Sort();
        void Show();
        void Clear();
        void SaveBinaryFile();
        void LoadBinaryFile();
        void fillRandom();
        int inputDataPrimitive();
        Train inputDataCustomObj();
    private:
        std::string BIN_FILE_INT = "./Files/primitiveData.bin";
        std::string BIN_FILE_TRAIN = "./Files/customObjData.bin";
        LinkedList<int> primitiveList;
        LinkedList<Train> customObjList;
        int typeSelector = 0; // 0 - operations will be performed on int type list & 1 - operations will be performed on Train type list
        int modeSelector = 0; // 0 - program will run in standart mode & 1 - program will run in time-complexity mode                                                              
};