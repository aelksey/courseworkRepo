#include <Windows.h>
#include "./Drivers/Driver.h"
#include "./LinkedList.h"
#include "./CustomObject/Time.h"
#include "./Utils/Random.h"
//#include <iostream>
//#include <string>

int main(){
    setlocale(LC_ALL,"Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    //std::string FILENAME = "./Files/primitiveData.bin";
    Driver d;
    d.Start();
    /*
    LinkedList <int> l1;
    LinkedList <int> l2;
    l1.AddEnd(2);
    l1.AddEnd(5);
    l1.WriteBinary(FILENAME);
    l2.ReadBinary(FILENAME);
    std::cout << l2.c_str() << std::endl;

    Random r;
    Train t = r.randTrain();
    std::cout << t.c_str() << std::endl;
    */
    return 0;
}