#include <vector>
#include <iostream>

template <typename T> void printVector(std::vector<T> vec){
    for(auto i : vec){
        std::cout << i << " ";
    }
}