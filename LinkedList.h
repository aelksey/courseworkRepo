#pragma once

#define FILE_ERROR "Файл не существует."
#define EMPTY_ERROR "Список пуст."
#define BOUNDS_ERROR "Выход за границу списка."
#define NOT_FOUND_ERROR "Не найдено подходящих элементов."

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include "./CustomObject/Station.h"
#include "./CustomObject/Train.h"

// TODO : Add search & sort implementation

// TODO : Add binary file i/o

// LinkedList Node template implementation

template <typename T> class Node{
    public:
        Node();
        Node(T _data);
        Node(T _data, Node *_next);
        T getData();
        //void setData(T _data);
        Node *getNext();
        void setNext(Node *_next);
        std::string c_str();
    private:
        T data;
        Node *next;
};

template <typename T> Node<T>::Node():data(nullptr),next(nullptr){}

template <typename T> Node<T>::Node(T _data, Node *_next):data(_data),next(_next){}

template <typename T> Node<T>::Node(T _data):data(_data),next(nullptr){}

template <typename T> T Node<T>::getData(){return data;}

template <typename T> Node<T>* Node<T>::getNext(){return next;}

template <typename T> void Node<T>::setNext(Node *_next){next = _next;}

//template <typename T> void Node<T>::setData(T _data){data = _data;}

template <typename T> std::string Node<T>::c_str(){
    std::stringstream ss;
    ss << data << " ";
    return ss.str();
}


// LinkedList template implementation

template <typename T> class LinkedList{
    public:
        LinkedList();
        // TODO : Add required operations
        void AddBeg(T data);
        void AddEnd(T data);
        void Add(T data,int pos);
        void DeleteBeg();
        void DeleteEnd();
        void Delete(int pos);
        void Sort(); // Sorts list using merge-sort algorithm
        std::vector<T> Search(T key);

        std::vector<Train> SearchByStation(std::string StationName){ // Specialization for Train type
            if(!isEmpty()){
                std::vector<Train> tempVec;
                Node<Train> *temp = head;
                while(temp != nullptr){
                    if(temp->getData().getArrivalStaion().getName() == StationName) tempVec.push_back(temp->getData());
                    temp = temp->getNext();
                }
            if(tempVec.size() != 0){
                return tempVec;
            }else{std::cout << NOT_FOUND_ERROR << std::endl;}
        }else{std::cout << EMPTY_ERROR;}
        }
        
        // Service sort functions
        Node<T> *split(Node<T> *_head);
        Node<T> *merge(Node<T> *first, Node<T> *second);
        Node<T> *MergeSort(Node<T> *_head);
        T getBeg();
        T getEnd();
        T get(int pos);
        // Binary file
        void WriteBinary(std::string filename);
        void ReadBinary(std::string filename);
        std::string c_str();
        int isEmpty();
        int getSize();
    private:
        Node<T> *head;
        Node<T> *tail;
        int size;
};

template <typename T> LinkedList<T>::LinkedList():head(nullptr),tail(nullptr),size(0){}

template <typename T> int LinkedList<T>::isEmpty(){
    return head == nullptr ? 1 : 0;
}

template <typename T> int LinkedList<T>::getSize(){
    if(isEmpty())size == 0;
    return size;
}

// Getters

template <typename T> T LinkedList<T>::getBeg(){
    if(isEmpty()) std::cout << EMPTY_ERROR << std::endl;
    else return head->getData();
}

template <typename T> T LinkedList<T>::getEnd(){
    if(isEmpty()) std::cout << EMPTY_ERROR << std::endl;
    else return tail->getData();
}

template <typename T> T LinkedList<T>::get(int pos){
    int flag = 0;
    if(isEmpty()) std::cout << EMPTY_ERROR << std::endl;
    if(pos == 0 && !flag){getBeg();flag = 1;}
    if(pos == getSize() && !flag){getEnd();flag = 1;}
    else if(!flag){
        Node<T> *temp = head;
        for(int i = 0; i < pos;i++){temp = temp->getNext();}
        return temp->getData();
    }
}

// Adders

template <typename T> void LinkedList<T>::AddBeg(T data){
    Node<T> *temp = new Node<T>(data);
    if(isEmpty()){head = temp;size++;}
    else{
        temp->setNext(head->getNext());
        head = temp;
        size++;
    }
}

template <typename T> void LinkedList<T>::AddEnd(T data){
    Node<T> *temp = new Node<T>(data);
    if(isEmpty()){AddBeg(data);}
    else{
        Node<T> *temp = head;
        Node<T> *newNode = new Node<T>(data);
        for(int i = 0; i < size-1; i++){temp = temp->getNext();}
        temp->setNext(newNode);
        tail = newNode;
        size++;
    }
}

template <typename T> void LinkedList<T>::Add(T data,int pos){ // Moves element in place of inserted backwards to the tail
    int flag = 0;
    if(pos <= 0) AddBeg(data);
    if(pos == getSize()){AddEnd(data);flag = 1;}
    if(pos > getSize()) std::cout << BOUNDS_ERROR;
    if(!flag){
        if(pos < getSize()){
            Node<T> *temp = head;
            Node<T> *newNode = new Node<T>(data);
            for (int i = 0; i < pos - 1; i++){
                temp = temp->getNext();
            }
            newNode->setNext(temp->getNext());
            temp->setNext(newNode);
            size++;
            }
    }
    
}

// Deletors

template <typename T> void LinkedList<T>::DeleteBeg(){
    if(isEmpty()){std::cout << EMPTY_ERROR << std::endl;}
    else{
        head = head->getNext();
        size--;
    }
}

template <typename T> void LinkedList<T>::DeleteEnd(){
    Node<T> *temp = head;
    if(isEmpty()){std::cout << EMPTY_ERROR << std::endl;}
    if(size == 1){DeleteBeg();}
    else{
        for(int i = 0;i < size-2;i++){temp = temp->getNext();}
        tail = temp;
        temp->setNext(nullptr);
        size--;
    }
}

template <typename T> void LinkedList<T>::Delete(int pos){
    int flag = 0;
    if(!isEmpty()){
        if(pos <= 0){DeleteBeg();flag = 1;}
        if(pos == getSize()){DeleteEnd();flag = 1;}
        if(pos > getSize() && !flag){std::cout << BOUNDS_ERROR;}
        if(!flag){
            Node<T> *temp = head;
            for (int i = 0; i < pos - 1; i++){
                temp = temp->getNext();
            }
            temp->setNext(temp->getNext()->getNext());
            size--;
        }
    }else{std::cout << EMPTY_ERROR << std::endl;}
}

// Sorting

template <typename T> Node<T> *LinkedList<T>::split(Node<T> *_head) {
    Node<T> *fast = _head;
    Node<T> *slow = _head;
    // Move fast pointer two steps and slow pointer
    // one step until fast reaches the end
    while (fast != nullptr && fast->getNext() != nullptr) {
        fast = fast->getNext()->getNext();
        if (fast != nullptr) {
            slow = slow->getNext();
        }
    }
    // Split the list into two halves
    Node<T> *temp = slow->getNext();
    slow->setNext(nullptr);
    return temp;
}

template <typename T> Node<T> *LinkedList<T>::merge(Node<T> *first, Node<T> *second) {
    // If either list is empty, return the other list
    if (first == nullptr) return second;
    if (second == nullptr) return first;
    // Pick the smaller value between first and second nodes
    if (first->getData() < second->getData()) {
        // Recursively merge the rest of the lists and
        // link the result to the current node
        first->setNext(merge(first->getNext(), second));
        return first;
    }
    else {
        // Recursively merge the rest of the lists
        // and link the result to the current node
        second->setNext(merge(first, second->getNext()));
        return second;
    }
}

template <typename T> Node<T> *LinkedList<T>::MergeSort(Node<T> *_head){
    // Base case: if the list is empty or has only one node, 
    // it's already sorted
    if (_head == nullptr || _head->getNext() == nullptr)
        return _head;
    // Split the list into two halves
    Node<T> *second = split(_head);
    // Recursively sort each half
    _head = MergeSort(_head);
    second = MergeSort(second);
    // Merge the two sorted halves
    return merge(_head, second);
}

template <typename T> void LinkedList<T>::Sort(){
    head = MergeSort(head);
}

// Search

template <typename T> std::vector<T> LinkedList<T>::Search(T key){ // Returns vector of positions of given element in case of sucsess
    int pos = 0;
    if(!isEmpty()){
        std::vector<T> tempVec;
        Node<T> *temp = head;
        while(temp != nullptr){
            if(temp->getData() == key) tempVec.push_back(pos);
            temp = temp->getNext();
            pos++;
        }
        if(tempVec.size() != 0){
            return tempVec;
        }else{std::cout << NOT_FOUND_ERROR << std::endl;}
    }else{std::cout << EMPTY_ERROR;}
}


// Binary file I/O

template <typename T> void LinkedList<T>::WriteBinary(std::string filename){
    std::ofstream ofs(filename, std::ios::binary | std::ios::out);
    if(ofs){
        Node<T> *temp = head;
        int _size = getSize();
        ofs.write((char*)&_size,sizeof(_size));
        while (temp != nullptr){
            T data = temp->getData();
            ofs.write((char*)&data,sizeof(data));
            temp = temp->getNext();
        }
        ofs.close();
    }else{std::cout << FILE_ERROR << std::endl;}
}

template <typename T> void LinkedList<T>::ReadBinary(std::string filename){
    std::ifstream ifs(filename, std::ios::binary | std::ios::in);
    if(ifs){
        int _size = 0;
        ifs.read((char*)&_size,sizeof(_size));
        if(_size > 0){
            T data;
            for(int i = 0;i < _size;i++){
                ifs.read((char*)&data,sizeof(data));
                AddEnd(data);
            }

        }
        ifs.close();
    }else{std::cout << FILE_ERROR  << std::endl;}
}


// c_str()

template <typename T> std::string LinkedList<T>::c_str(){
    std::stringstream ss;
    Node<T> *temp = head;
    ss << "Размер:" << getSize() << " Элементы:" << std::endl << std::endl;
    if(isEmpty()){
        std::cout << EMPTY_ERROR;
    }else{
        while (temp != nullptr){
        ss << temp->c_str() << std::endl;
        temp = temp->getNext();
        }
        ss << std::endl;
    }
    return ss.str();
}


