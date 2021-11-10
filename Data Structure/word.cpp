#include<iostream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "word.h"

using namespace std;

Word::Word() {
    string eng = "hello";
    string type = "verb";
    string meaning = "xin chào";
    WORD *pNext = NULL;
}
Word::Word(string eng, string type, string meaning, int key) {
    this->eng = eng;
    this->type = type; 
    this->meaning = meaning;
    this->key = this->genKey();
}
Word::Word(const Word &w) {
    eng = w.eng;
    type = w.type;
    meaning = w.meaning;
}

// void Word::inputWord() {
//     cout << "Nhập từ tiếng anh: "; 
//     cin >> eng;
//     cout << "Nhập loại từ: ";
//     cin >> type;
//     cout << "Nhập nghĩa: ";
//     cin.ignore();
//     getline(cin, meaning);
// }
void Word::display() {
    cout << genKey();
    cout << ". "<< eng << " (" << type << ") : " << meaning;
}

int Word::genKey() {
    int key = 0; 
    for (int i = 0; i < eng.length(); i++)
    {
        key += (int(eng[i]) - 97);
    }
    return key;
}
void Word::replaceSpace() {
    int x, length;
    length = eng.length();
    //Random 1 vị trí bất kì trong 1 từ
    x = rand() % (length-1); //sources: https://www.cplusplus.com/reference/cstdlib/rand/
    eng[x] = '_';
}
