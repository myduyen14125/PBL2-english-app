#include<iostream>
#include<string>
#include<fstream>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
using namespace std;

typedef class word Word;

class word {
    private: 
        string eng;
        string type;
        string meaning;
        Word *pNext;
    public: 
        int randomSpace(int length);
};

int word::randomSpace(int length) {
    return rand() % (length-1); //Random 1 vi tri bat ki trong 1 tu
}
