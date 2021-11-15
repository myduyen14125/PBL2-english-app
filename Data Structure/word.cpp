#include<iostream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "word.h"

using namespace std;

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
