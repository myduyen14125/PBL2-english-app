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
        WORD *pNext;
    public: 
        Word(); //defaut destructor
        Word(string, string, string);
        Word(const Word &);
        ~Word() {delete [] pNext;};

        void inputWord(); //Nhap từ
        void display(); //Xuất từ 

        int randomSpace(); //Random 1 vị trí bất kì trong 1 từ
        int replaceSpace(char character[]);//Thay thế kí tự bằng space

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
    pNext = w.pNext;
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
    cout << eng << ": (" << type << ") : " << meaning << endl;
}
int Word::randomSpace() {
    int length = eng.length();
    return rand() % (length-1); //sources: https://www.cplusplus.com/reference/cstdlib/rand/
}
int main() {
    Word w;
    w.inputWord();
    w.display();
    return 0;
}