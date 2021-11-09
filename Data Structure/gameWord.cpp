#include<iostream>
#include<list>  //STL
#include "word.cpp"
#include "hashTable.cpp"
#include<cstring>
using namespace std;

class gameWord {
    private: 
        HashTable h;
        int size;
    public: 
        friend class HashTable;
};