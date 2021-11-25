#include<iostream>
#include <fstream>
#include "hashTable.h"
#include <iomanip>
#include<string.h>

using namespace std;

HashTable::HashTable() {
    for (int i = 0; i < hashGroups; i++) {
    	table[i] = nullptr;
    }
    this->readFile();
}
HashTable::~HashTable() {
	
}
void HashTable::readFile() {
	ifstream FileIn;
    FileIn.open("E:\\PBL2-english-app\\data.txt", ios_base::in);
    if (FileIn.fail()) {
        cout << "Data update failed!" << endl;
    }
    Word word;
    string line;
    while (!FileIn.eof()) {
        getline(FileIn, line);
        if(line != "")
        {
        	formatWord(word, line);
			insertWord(word.eng, word.type, word.meaning);
		}
    }
    FileIn.close();
}
void HashTable::updateFile() {
	int i = 0;
	ofstream FileOut;
	FileOut.open("E:\\PBL2-english-app\\data.txt", ios::out);
	while(i < hashGroups)
	{
		Word *run = table[i];
        while(run != nullptr) {
           	FileOut<<run->eng<<"@"<<run->type<<"@"<<run->meaning<<"@"<<endl;
           	run = run->right;
		}
		i++;
	}
	FileOut.close();
}
bool HashTable::isEmpty() const {
    if(wordCount == 0)	return true;
    else return false;
}

int HashTable::hashFunction(string eng) { 
    if (eng != "") {
        char x = eng[0];
        if ((x > 96) && (x < 123)) { //Ascii tu a-z
            return (int)x - 97;
        }
    }
    return -1;
}

void HashTable::insertWord(string eng, string type, string meaning) {
	Word* newWord = new Word;
	newWord->eng = eng;
	newWord->type = type;
	newWord->meaning = meaning;
	newWord->left = nullptr;
	newWord->right = nullptr;
    int key = hashFunction(newWord->eng);
    Word* run  = table[key];
    
    if(table[key] == nullptr) {
    	table[key] = newWord;
    	table[key]->left = nullptr;
    	table[key]->right = nullptr;
	}
	else if(newWord->eng < run->eng) {
		newWord->right = run;
		run->left = newWord;
		table[key] = newWord;
	}
	else {
		Word* temp;
		while(run->eng < newWord->eng) {
			if(run->right == nullptr)	break;
			run = run->right;
		}	
		if(run->eng < newWord->eng && run->right == nullptr) {
			run->right = newWord;
			newWord->left = run;
		}
		else {
			temp = run->left;
			newWord->right = run;
			newWord->left = temp;
			temp->right = newWord;
			run->left = newWord;
		}
	}
	countElements[key]++;
	wordCount++;
}
void HashTable::removeWord(string eng) {
    int key = hashFunction(eng);
    if(table[key] == nullptr)
    	cout<<"Khong ton tai word can xoa"<<endl;
    else {
    	Word* run  = table[key];
    	if(run->eng == eng) {
    		if(run->right == nullptr) 	run = nullptr;
			else	run = run->right;
			table[key] = run;
		}
		else {
			bool check = false;
			while(run != nullptr) {
				if(run->right == nullptr) {
					break;
				}
				if(run->right->eng == eng) {
					run->right = run->right->right;
					check = true;
					wordCount--;
					break;
				}
				run = run->right;
			}
			if(!check)	cout<<"Khong ton tai word can xoa"<<endl;
		}
	}
}
void HashTable::formatWord(Word &word, string line) {
	string s = "";
	int i = 0;
	while(line[i] != '@') {
        s += line[i];
        i++;
	}
	i++;
	word.eng = s;
	s = "";
	while(line[i] != '@') {
        s += line[i];
        i++;
	}
	i++;
	word.type = s;
	s = "";
	while(line[i] != '@') {
      	s += line[i];
       	i++;
	}
	word.meaning = s;
}

void HashTable::printTable() {
    for (int i = 0; i < hashGroups; i++) {
    	int dem = 0;
        Word *run = table[i];
        while(run != nullptr) {
           	cout<<setw(20)<<run->eng<<setw(15)<<run->type<<setw(20)<<run->meaning<<endl;
           	run = run->right;
		}
    }
}
string HashTable::leftWord(string leftWord) {
	int key;
	if(leftWord == "") {
		key = 0;
	}
	else {
		key = hashFunction(leftWord);
	}
	
	Word *run = table[key];
	if(table[key] == nullptr || table[key]->eng >= leftWord) {
		while(table[key] == nullptr || table[key]->eng >= leftWord) {
			key--;
			if(key < 0) {
				return "";
			}
		}
		run = table[key];
		while(run->right != nullptr) {
			run = run->right;
		}
		return run->eng;
	}
	else {
		bool isNull = false;
		while(run != nullptr && run->eng < leftWord) {
			if(run->right == nullptr) {
				isNull = true;
				break;
			}
			else run = run->right;
		}
		if(isNull) return run->eng;
		else return run->left->eng;
	}
}
string HashTable::rightWord(string rightWord) {
	int key;
	if(rightWord == "") {
		key = 0;
	}
	else {
		key = hashFunction(rightWord);
	}
	
	Word *run = table[key];
	
	if(table[key] == nullptr || table[key]->eng > rightWord) {
		while(table[key] == nullptr) {
			key++;
			if(key > 25) {
				return "zzz";
			}
		}
		return table[key]->eng;
	}
	else {
		while(run != nullptr && run->eng <= rightWord) {
			run = run->right;
		}
		if(run == nullptr) {
			while(run == nullptr) {
				key++;
				if(key > 25) {
					return "zzz";
				}
				run = table[key];
			}
			return run->eng;
		}
		else {
			return run->eng;
		}
		
	}
}
void HashTable::searchTable(string word, Text tiengAnh[], Text tuLoai[], Text nghia[], int &countReadWord) {
	countReadWord = 0;
	int key;
	if(word == "") {
		key = 0;
	}
	else {
		key = hashFunction(word);
	}
	
	Word *run = table[key];
	if(word != "") {
		if(table[key] == nullptr) {
			while(table[key] == nullptr) {
				key++;
				if(key > 25) {
					break;
				}
			}
		}
		else {
			while(run != nullptr && run->eng < word) {
				run = run->right;
			}
			if(run == nullptr) {
				while(run == nullptr) {
					key++;
					if(key > 25)	break;
					run = table[key];
				}
			}
		}
	}

	for(int i = 0; i < 7; i++) {
		if(run == nullptr) {
			key++;
			if(key > 25)	break;
			run = table[key];
			i--;
		}
		else {
			tiengAnh[i].setString(run->eng);
			tuLoai[i].setString(run->type);
			nghia[i].setString(": " + run->meaning);
			countReadWord++;
			run = run->right;
		}
	}
}



