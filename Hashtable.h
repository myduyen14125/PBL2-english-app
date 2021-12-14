#ifndef HASHTABLE_H
#define HASHTABLE_H

#include"Word.h"
#include<stdlib.h> 
#include<ctime>
#include<fstream>
#include<iostream>
#include<iomanip>
using namespace std;

class HashTable {
	private:
		const static int hashGroups = 26;
		int countElements[26] = {0}; // random tu choi game cua list
        int wordCount = 0; // so luong tu trong tu dien
		WordEng headTable[hashGroups];
		WordEng tailTable[hashGroups];
	public:
		HashTable();
		~HashTable();
		
		void readFile();
		void updateFile();
		WordEng formatWord(string);
		
        bool isEmpty();
        int hashFunction(string eng);
        
        int findViewWord(WordEng word[], WordEng tempWord);
        WordEng findWord(string eng);
        WordEng findFirstWord();
        WordEng findLeftWord(WordEng eng);
        WordEng findRightWord(WordEng eng);
        
        bool insertWord(WordEng);
        void removeWord(WordEng);
        void editWord(WordEng oldWord, WordEng newWord);
        int getCountWord();
        WordEng randomWord() const;
        void printTable();
};
#endif
