#include<iostream>
#include <string.h>
#ifndef WORD_H 
#define WORD_H

using namespace std;

typedef class Word WORD;

class Word {
    public: 
        string eng;
        string type;
        string meaning;
        int key;
        WORD *pNext = NULL;
    public: 
        Word(); //defaut destructor
        Word(string, string, string, int);
        Word(const Word &);
        ~Word() {delete [] pNext;};

        void inputWord(); //Nhap từ
        void display(); //Xuất từ 

        string getEng() {return eng;}

        int genKey();
        void replaceSpace();//Thay thế kí tự bằng space

};

#endif