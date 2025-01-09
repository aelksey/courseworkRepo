#include "Driver.h"
#include "../Utils/Utils.h"
#include "../CustomObject/Train.h"
#include "../CustomObject/Time.h"
#include "../CustomObject/Station.h"
#include "../Utils/Random.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>

// std::cout << "" << std::endl;
// std::abort()

Driver::Driver(){}

int Driver::inputDataPrimitive(){
    int input;
    std::cout << "Введите элемент (число):" << std::endl;
    std::cin >> input;
    if(input == 0){std::cout << "Неверный формат ввода, введите число" << std::endl;std::abort();}
    return input;
}

Train Driver::inputDataCustomObj(){
    Train t;
    std::cin >> t;
    return t;
}

void Driver::showAbout(){
    std::cout << "Курсовая: Тема 1.1.3 Простые структуры данных в памяти - Движение поездов." << std::endl;
    std::cout << "Структура данных: односвязный список(Singly Linked List)" << std::endl;
}

void Driver::askMode(){
    char input;
    std::cout << "Запустить режим подсчёта временной(Big O) сложности?" << std::endl;
    std::cout << "0. Выйти из тестирующей программы" << std::endl;
    std::cout << "1. Да" << std::endl;
    std::cout << "2. Нет" << std::endl;
    while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){modeSelector = 1;break;} 
        if(input == '2'){modeSelector = 2;break;}
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
}

void Driver::askType(){
    char input;
    std::cout << "Выберите тип данных содержимого списка:" << std::endl;
    std::cout << "0. Выйти из тестирующей программы" << std::endl;
    std::cout << "1. Примитив(целочисленный int)" << std::endl;
    std::cout << "2. Объект(поезд Train)" << std::endl;
    
    while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){typeSelector = 1;break;} 
        if(input == '2'){typeSelector = 2;break;}
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
}

void Driver::showMenu(){
    if(modeSelector == 1){
        showMenuTimeComplexity();
    }
    if(modeSelector == 2){
        showMenuStandart();
    }
}

void Driver::showMenuTimeComplexity(){
    char input;
    std::cout << "Для какой операции подсчитать сложность?" << std::endl;
    std::cout << "0. Выйти из тестирующей программы" << std::endl;
    std::cout << "1. Добавление" << std::endl;
    std::cout << "2. Удаление" << std::endl;
    std::cout << "3. Поиск" << std::endl;
    std::cout << "4. Сортировка" << std::endl;
    std::cout << "5. Полный подсчёт по всем операциям" << std::endl;
    while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){timeComplexityAdd();break;} 
        if(input == '2'){timeComplexityRemove();break;}
        if(input == '3'){timeComplexitySearch();break;}
        if(input == '4'){timeComplexitySort();break;}
        if(input == '5'){timeComplexityFull();break;}
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
}

void Driver::timeComplexityAdd(){
    int n = 1000;
    int inc = n;
    if(typeSelector == 1){
        std::cout << "Расчёт по операции добавления для типа int." << std::endl;
        std::cout << "Расчёт производится на объёме данных n = 1000 - 10 000 , проводится 10 временнах измерений с шагом 500 элементов." << std::endl;
        for(int i = 0; i < 10;i++){
            calculateTimeComplexityAdd(n);
            n = n + inc;
        }
    }
    if(typeSelector == 2){
        std::cout << "Расчёт по операции добавления для типа Train" << std::endl;
        std::cout << "Расчёт производится на объёме данных n = 1000 - 10 000 , проводится 10 временнах измерений с шагом 500 элементов." << std::endl;
        for(int i = 0; i < 10;i++){
            calculateTimeComplexityAdd(n);
            n = n + inc;
        }
    }
}

void Driver::timeComplexityRemove(){
    int n = 1000;
    int inc = n;
    if(typeSelector == 1){
        std::cout << "Расчёт по операции удаления для типа int." << std::endl;
        std::cout << "Расчёт производится на объёме данных n = 1000 - 10 000 , проводится 10 временнах измерений с шагом 1000 элементов." << std::endl;
        for(int i = 0; i < 10;i++){
            calculateTimeComplexityRemove(n);
            n = n + inc;
        }
    }
    if(typeSelector == 2){
        std::cout << "Расчёт по операции удаления для типа Train" << std::endl;
        std::cout << "Расчёт производится на объёме данных n = 1000 - 10 000 , проводится 10 временнах измерений с шагом 1000 элементов." << std::endl;
        for(int i = 0; i < 10;i++){
            calculateTimeComplexityRemove(n);
            n = n + inc;
        }
    }
}

void Driver::timeComplexitySort(){
    int n = 1000;
    int inc = n;
    if(typeSelector == 1){
        std::cout << "Расчёт по операции сортировки для типа int." << std::endl;
        std::cout << "Расчёт производится на объёме данных n = 1000 - 10 000 , проводится 10 временнах измерений с шагом 1000 элементов." << std::endl;
        for(int i = 0; i < 10;i++){
            calculateTimeComplexitySort(n);
            n = n + inc;
        }
    }
    if(typeSelector == 2){
        std::cout << "Расчёт по операции сортировки для типа Train" << std::endl;
        std::cout << "Расчёт производится на объёме данных n = 1000 - 10 000 , проводится 10 временнах измерений с шагом 1000 элементов." << std::endl;
        for(int i = 0; i < 10;i++){
            calculateTimeComplexitySort(n);
            n = n + inc;
        }
    }
}

void Driver::timeComplexitySearch(){
    int n = 1000;
    int inc = n;
    if(typeSelector == 1){
        std::cout << "Расчёт по операции поиска для типа int." << std::endl;
        std::cout << "Расчёт производится на объёме данных n = 1000 - 10 000 , проводится 10 временнах измерений с шагом 1000 элементов." << std::endl;
        std::cout << "Необходимый для поиска элемент в структуре помещается по позиции n/2" << std::endl;
        for(int i = 0; i < 10;i++){
            calculateTimeComplexitySearch(n);
            n = n + inc;
        }
    }
    if(typeSelector == 2){
        std::cout << "Расчёт по операции поиска для типа Train" << std::endl;
        std::cout << "Расчёт производится на объёме данных n = 1000 - 10 000 , проводится 10 временнах измерений с шагом 1000 элементов." << std::endl;
        std::cout << "Необходимый для поиска элемент в структуре помещается по позиции n/2" << std::endl;
        for(int i = 0; i < 10;i++){
            calculateTimeComplexitySearch(n);
            n = n + inc;
        }
    }
}

void Driver::timeComplexityFull(){
    timeComplexityAdd();
    timeComplexityRemove();
    timeComplexitySearch();
    timeComplexitySort();
}

void Driver::calculateTimeComplexityAdd(int n){
    Random r;
    if(typeSelector == 1){
        auto start = std::chrono::system_clock::now();
        // Some computation here
        for (int i = 0; i < n;i++) primitiveList.AddEnd(r.randInt(0,1000));
        // Some computation here
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "n = " << n << " t = " << elapsed_seconds.count() << "s" << std::endl;
        ClearNoEcho();
    }
    if(typeSelector == 2){
        auto start = std::chrono::system_clock::now();
        // Some computation here
        for (int i = 0; i < n;i++) customObjList.AddEnd(r.randTrain());
        // Some computation here
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "n = " << n << " t = " << elapsed_seconds.count() << "s" << std::endl;
        ClearNoEcho();
    }
}

void Driver::calculateTimeComplexityRemove(int n){
    Random r;
    if(typeSelector == 1){
        for (int i = 0; i < n;i++) primitiveList.AddEnd(r.randInt(0,1000));
        auto start = std::chrono::system_clock::now();
        // Some computation here
        for (int i = 0; i < n;i++) primitiveList.DeleteEnd();
        // Some computation here
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "n = " << n << " t = " << elapsed_seconds.count() << "s" << std::endl;
    }
    if(typeSelector == 2){
        for (int i = 0; i < n;i++) customObjList.AddEnd(r.randTrain());
        auto start = std::chrono::system_clock::now();
        // Some computation here
        for (int i = 0; i < n;i++) customObjList.DeleteEnd();
        // Some computation here
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "n = " << n << " t = " << elapsed_seconds.count() << "s" << std::endl;
    }
}

void Driver::calculateTimeComplexitySearch(int n){
    Random r;
   if(typeSelector == 1){
        int value = r.randInt(0,99);
        int pos = n / 2; // constant middle position
        for (int i = 0; i < n;i++){
            primitiveList.AddEnd(r.randInt(0,99));
        }
        primitiveList.Add(r.randInt(0,99),pos);
        auto start = std::chrono::system_clock::now();
        // Some computation here
        primitiveList.Search(value);
        // Some computation here
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "pos = " << pos << " n = " << n << " t = " << elapsed_seconds.count() << "s" << std::endl;
        ClearNoEcho();
   }
   if(typeSelector == 2){
        Station value = r.randStation();
        int pos = n / 2; // constant middle position
        for (int i = 0; i < n;i++){
            customObjList.AddEnd(r.randTrain());
        }
        customObjList.Add(r.randTrain(),pos);
        auto start = std::chrono::system_clock::now();
        // Some computation here
        customObjList.SearchByStation(value.getName());
        // Some computation here
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "pos = " << pos << " n = " << n << " t = " << elapsed_seconds.count() << "s" << std::endl;
        ClearNoEcho();
   }
}

void Driver::calculateTimeComplexitySort(int n){
    Random r;
    if(typeSelector == 1){
        for (int i = 0; i < n;i++) primitiveList.AddEnd(r.randInt(0,1000));
        auto start = std::chrono::system_clock::now();
        // Some computation here
        for (int i = 0; i < n;i++) primitiveList.Sort();
        // Some computation here
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "n = " << n << " t = " << elapsed_seconds.count() << "s" << std::endl;
        ClearNoEcho();
    }
    if(typeSelector == 2){
        for (int i = 0; i < n;i++) customObjList.AddEnd(r.randTrain());
        auto start = std::chrono::system_clock::now();
        // Some computation here
        for (int i = 0; i < n;i++) customObjList.Sort();
        // Some computation here
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        std::cout << "n = " << n << " t = " << elapsed_seconds.count() << "s" << std::endl;
        ClearNoEcho();
    }
}

void Driver::ClearNoEcho(){
    if(typeSelector == 1){
        while (!primitiveList.isEmpty()) primitiveList.DeleteEnd();
    }
    if(typeSelector == 2){
        while (!customObjList.isEmpty()) customObjList.DeleteEnd();
    }
}

void Driver::showMenuStandart(){
    if(typeSelector == 1){
        showOperationsPrimitive();
    }
    if(typeSelector == 2){
        showOperationsCustomObj();
    }
}

void Driver::showOperationsPrimitive(){
    char input;
    std::cout << "Выберите необходимую операцию:" << std::endl;
    std::cout << "0. Выйти из тестирующей программы" << std::endl;
    std::cout << "1. Добавление" << std::endl;
    std::cout << "2. Удаление" << std::endl;
    std::cout << "3. Поиск" << std::endl;
    std::cout << "4. Сортировка" << std::endl;
    std::cout << "5. Отобразить текущее состояние структры" << std::endl;
    std::cout << "6. Считать из бинарного файла" << std::endl;
    std::cout << "7. Записать в бинарный файл" << std::endl;
    std::cout << "8. Очистить структуру" << std::endl;
    std::cout << "9. Заполнить случайными элементами" << std::endl;
    while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){Add();break;} 
        if(input == '2'){Delete();break;}
        if(input == '3'){Search();break;}
        if(input == '4'){Sort();break;}
        if(input == '5'){Show();break;}
        if(input == '6'){LoadBinaryFile();break;}
        if(input == '7'){SaveBinaryFile();break;}
        if(input == '8'){Clear();break;}
        if(input == '9'){fillRandom();break;}
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
}

void Driver::showOperationsCustomObj(){
    char input;
    std::cout << "Выберите необходимую операцию:" << std::endl;
    std::cout << "0. Выйти из тестирующей программы" << std::endl;
    std::cout << "1. Добавление" << std::endl;
    std::cout << "2. Удаление" << std::endl;
    std::cout << "3. Поиск" << std::endl;
    std::cout << "4. Сортировка" << std::endl;
    std::cout << "5. Отобразить текущее состояние структры" << std::endl;
    std::cout << "6. Считать из бинарного файла" << std::endl;
    std::cout << "7. Записать в бинарный файл" << std::endl;
    std::cout << "8. Очистить структуру" << std::endl;
    std::cout << "9. Заполнить случайными элементами" << std::endl;
    while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){Add();break;} 
        if(input == '2'){Delete();break;}
        if(input == '3'){Search();break;}
        if(input == '4'){Sort();break;}
        if(input == '5'){Show();break;}
        if(input == '6'){LoadBinaryFile();break;}
        if(input == '7'){SaveBinaryFile();break;}
        if(input == '8'){Clear();break;}
        if(input == '9'){fillRandom();break;}
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
}

void Driver::Add(){
    char input;
    std::cout << "Выберите тип операции:" << std::endl;
    std::cout << "0. Выйти из тестирующей программы" << std::endl;
    std::cout << "1. Добавление в начало" << std::endl;
    std::cout << "2. Добавление в конец" << std::endl;
    std::cout << "3. Добавление по позиции" << std::endl;
    if(typeSelector == 1){
        while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){primitiveList.AddBeg(inputDataPrimitive());break;} 
        if(input == '2'){primitiveList.AddEnd(inputDataPrimitive());break;}
        if(input == '3'){
        int input;
        std::cout << "По какой позиции добавить элемент?(введите число):" << std::endl;
        std::cin >> input;
        primitiveList.Add(inputDataPrimitive(),input);break;
        }
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
    std::cout << "Элемент добавлен" << std::endl;
    showOperationsPrimitive();
    }
    if(typeSelector == 2){
        while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){customObjList.AddBeg(inputDataCustomObj());break;} 
        if(input == '2'){customObjList.AddEnd(inputDataCustomObj());break;}
        if(input == '3'){
        int input;
        std::cout << "По какой позиции добавить элемент?(введите число):" << std::endl;
        std::cin >> input;
        customObjList.Add(inputDataCustomObj(),input);break;
        }
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
    std::cout << "Элемент добавлен" << std::endl;
    showOperationsCustomObj();
    }
}

void Driver::Delete(){
    char input;
    std::cout << "Выберите тип операции:" << std::endl;
    std::cout << "0. Выйти из тестирующей программы" << std::endl;
    std::cout << "1. Удаление из начала" << std::endl;
    std::cout << "2. Удаление из конца" << std::endl;
    std::cout << "3. Удаление по позиции" << std::endl;
    if(typeSelector == 1){
        while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){primitiveList.DeleteBeg();break;} 
        if(input == '2'){primitiveList.DeleteEnd();break;}
        if(input == '3'){
        int input;
        std::cout << "По какой позиции удалить элемент?(введите число):" << std::endl;
        std::cin >> input;
        primitiveList.Delete(input);break;
        }
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
    std::cout << "Элемент удалён" << std::endl;
    showOperationsPrimitive();
    }
    if(typeSelector == 2){
        while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){customObjList.DeleteBeg();break;} 
        if(input == '2'){customObjList.DeleteEnd();break;}
        if(input == '3'){
        int input;
        std::cout << "По какой позиции удалить элемент?(введите число):" << std::endl;
        std::cin >> input;
        customObjList.Delete(input);break;
        }
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
    std::cout << "Элемент добавлен" << std::endl;
    showOperationsCustomObj();
    }
}

void Driver::Search(){
    char input;
    std::cout << "Выберите тип операции:" << std::endl;
    std::cout << "0. Выйти из тестирующей программы" << std::endl;
    std::cout << "1. Поиск по ключевому значению(key)" << std::endl;
    std::cout << "2. Получить элемент из начала" << std::endl;
    std::cout << "3. Получить элемент из конца" << std::endl;
    std::cout << "4. Получить элемент по позиции" << std::endl;
    if(typeSelector == 1){
        while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){
            int input;
            std::cout << "Введите целочисленный ключ поиска(key):" << std::endl;
            std::cin >> input;
            printVector(primitiveList.Search(input));
            break;
        } 
        if(input == '2'){std::cout << primitiveList.getBeg() << std::endl;break;}
        if(input == '3'){std::cout << primitiveList.getEnd() << std::endl;break;}
        if(input == '4'){
            int input;
            std::cout << "По какой позиции получить элемент?(введите число):" << std::endl;
            std::cin >> input;
            std::cout << primitiveList.get(input) << std::endl;break;
        }
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
    std::cout << "Произведён поиск" << std::endl;
    showOperationsPrimitive();
    }
    if(typeSelector == 2){
       while(1){
        std::cin >> input;
        if(input == '0') std::abort();
        if(input == '1'){
            std::string input;
            std::cout << "Поиск всех поездов по станции прибытия:" << std::endl;
            std::cout << "Введите название станции:";
            std::cin >> input;
            printVector(customObjList.SearchByStation(input));
            break;
        } 
        if(input == '2'){std::cout << customObjList.getBeg().c_str() << std::endl;break;}
        if(input == '3'){std::cout << customObjList.getEnd().c_str() << std::endl;break;}
        if(input == '4'){
            int input;
            std::cout << "По какой позиции получить элемент?(введите число):" << std::endl;
            std::cin >> input;
            std::cout << customObjList.get(input).c_str() << std::endl;break;
        }
        else{std::cout << "Неверный формат ввода, введите число" << std::endl;}
    }
    std::cout << "Произведён поиск" << std::endl;
    showOperationsCustomObj();
    }
}

void Driver::Sort(){
    if(typeSelector == 1){
        primitiveList.Sort();
        std::cout << "Структура отсортирована" << std::endl;
        showOperationsPrimitive();
    }
    if (typeSelector == 2){
        customObjList.Sort();
        std::cout << "Структура отсортирована" << std::endl;
        showOperationsCustomObj();
    }
}

void Driver::Show(){
    if(typeSelector == 1){
        std::cout << primitiveList.c_str() << std::endl;
        showOperationsPrimitive();
    }
    if (typeSelector == 2){
        std::cout << customObjList.c_str() << std::endl;
        showOperationsCustomObj();
    }
}

void Driver::LoadBinaryFile(){
    if(typeSelector == 1){
        primitiveList.ReadBinary(BIN_FILE_INT);
        std::cout << "Структура загружена из файла" << std::endl;
        showOperationsPrimitive();
    }
    if(typeSelector == 2){
        customObjList.ReadBinary(BIN_FILE_TRAIN);
        std::cout << "Структура загружена из файла" << std::endl;
        showOperationsCustomObj();
    }
}

void Driver::SaveBinaryFile(){
   if(typeSelector == 1){
        primitiveList.WriteBinary(BIN_FILE_INT);
        std::cout << "Структура сохранена в файл" << std::endl;
        showOperationsPrimitive();
    }
    if(typeSelector == 2){
        customObjList.WriteBinary(BIN_FILE_TRAIN);
        std::cout << "Структура сохранена в файл" << std::endl;
        showOperationsCustomObj();
    }
}

void Driver::Clear(){
    if(typeSelector == 1){
        while (!primitiveList.isEmpty()) primitiveList.DeleteEnd();
        std::cout << "Структура очищена" << std::endl;
        showOperationsPrimitive();
    }
    if(typeSelector == 2){
        while (!customObjList.isEmpty()) customObjList.DeleteEnd();
        std::cout << "Структура очищена" << std::endl;
        showOperationsCustomObj();
    }
}

void Driver::fillRandom(){
    Random r;
    int input;
    std::cout << "Введите кол-во элементов для заполнения:";
    std::cin >> input;
    if(input == 0){std::cout << "Неверный формат ввода, введите число" << std::endl;std::abort();}
    if(typeSelector == 1){
        for(int i = 0; i < input;i++)primitiveList.AddEnd(r.randInt(0,100));
        std::cout << "Структура заполнена:" << std::endl;
        showOperationsPrimitive();
    }
    if(typeSelector == 2){
        for(int i = 0; i < input;i++)customObjList.AddEnd(r.randTrain());
        std::cout << "Структура заполнена:" << std::endl;
        showOperationsCustomObj(); 
    }
}

void Driver::Start(){
    showAbout();
    askType();
    askMode();
    showMenu();
}