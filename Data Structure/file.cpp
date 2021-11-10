#include<iostream>
#include <fstream>
#include "word.cpp"
#include "hashTable.cpp"
#ifndef FILE_H
#define FILE_H

using namespace std;

class file {
    private:  
        int size;
    public:  
        friend class Word;
        friend class HashTable;
        bool importFile();
        void update();
        void storeData();
};

#endif

bool file::importFile() {
    ifstream fileIn;
    fileIn.open("data.txt", ios::in);
    int i = 0; 
    if (fileIn.fail()) {
        cout << "Data update failed!";
        return false;
    }
    Word w;
    HashTable HT;
    while (!fileIn.eof()) {
        i++; 
        fileIn >> w.eng;
        fileIn >> w.type;
        fileIn >> w.meaning;
        //Tòn thêm fileIn vô đây hỉ
        HT.insertItem(w);
    }
    this->size = i - 1;
    fileIn.close();
    return true;
}