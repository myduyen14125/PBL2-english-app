#include<list>  //STL
#include "word.cpp"

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

class HashTable {
    private: 
        int hashGroups;
        list<Word> *table;
    public:
        friend class Word;
        HashTable(int b = 7); //default constructor

        bool isEmpty() const;
        int hashFunction(int key);

        void insertItem(Word w);
        void removeItem(int key);
        void searchTable(string eng);

        void readFile();
        void printTable();
};

#endif