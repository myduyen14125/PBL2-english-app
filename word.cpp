#include<iostream>
#include<fstream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
using namespace std;

#ifndef WORD_H
#define WORD_H

typedef class Word WORD;

class Word {
    private: 
        string eng;
        string type;
        string meaning;
        WORD *pNext = NULL;
    public: 
        Word(); //defaut destructor
        Word(string, string, string);
        Word(const Word &);
        ~Word() {delete [] pNext;};

        void inputWord(); //Nhap từ
        void display(); //Xuất từ 

        void replaceSpace();//Thay thế kí tự bằng space

};
#endif

Word::Word() {
    string eng = "hello";
    string type = "verb";
    string meaning = "xin chào";
    WORD *pNext = NULL;
}
Word::Word(string eng, string type, string meaning) {
    this->eng = eng;
    this->type = type; 
    this->meaning = meaning;
}
Word::Word(const Word &w) {
    eng = w.eng;
    type = w.type;
    meaning = w.meaning;
}

void Word::inputWord() {
    cout << "Nhập từ tiếng anh: "; 
    cin >> eng;
    cout << "Nhập loại từ: ";
    cin >> type;
    cout << "Nhập nghĩa: ";
    cin.ignore();
    getline(cin, meaning);
}
void Word::display() {
    cout << eng << " (" << type << ") : " << meaning << endl;
}

void Word::replaceSpace() {
    int x, length;
    length = eng.length();
    //Random 1 vị trí bất kì trong 1 từ
    x = rand() % (length-1); //sources: https://www.cplusplus.com/reference/cstdlib/rand/
    eng[x] = '_';
}

int main() {
    Word w;
    w.inputWord();
    w.display();
    w.replaceSpace();
    w.display();
    return 0;
}