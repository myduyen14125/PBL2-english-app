#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "library.h"
<<<<<<< HEAD

=======
#include <stdlib.h> 
#include <ctime>
using namespace std;
>>>>>>> master
class HashTable {
    private: 
		struct Word {
		    string eng;
		    string type;
		    string meaning;
		    Word* left;
		    Word* right;
		};
		const static int hashGroups = 26;
		int countElements[hashGroups] = {0}; // random tu choi game cua list
        int wordCount = 0; // so luong tu trong tu dien
		Word* table[hashGroups];
    public:
        HashTable();
		~HashTable();
		
		void readFile();
		void updateFile();
        bool isEmpty() const;
        int hashFunction(string eng);
		
        void insertWord(string eng, string type, string meaning);
        void removeWord(string eng);
        string leftWord(string leftWord);
        string rightWord(string rightWord);
        void searchTable(string word, Text tiengAnh[], Text tuLoai[], Text nghia[], int &countReadWord);

        void formatWord(Word &word, string line);
        void printTable();
        
        void randomWord(string &english, string &type, string &meaning);
};

#endif
