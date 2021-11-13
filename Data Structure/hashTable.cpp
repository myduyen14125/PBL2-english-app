#include<iostream>
#include <fstream>
#include<list>  
#include "hashTable.h"
#include<cstring>
using namespace std;

HashTable::HashTable(int b) {
    this->hashGroups = b;
    table = new list<Word>[hashGroups];
}

bool HashTable::isEmpty() const {
    int sum{};
    for (int i{}; i < hashGroups; i++) {
        sum += table[i].size();
    }
    if (!sum) {
        return true;
    }
    return false;
}


int HashTable::hashFunction(int key) {
    return key % hashGroups;
}
void HashTable::insertItem(Word w) {
    int index = hashFunction(w.genKey());
    table[index].push_back(w);
}
void HashTable::removeItem(int key) {
    int index = hashFunction(key); //get the hash index of key 

    //find the key in the index list 
    list<Word>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) {
        if (i->genKey() == key)
            break;
    } 
    
    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}
bool HashTable::readFile() {
    ifstream FileIn;
    FileIn.open("data.txt", ios_base::in);
    int i = 0; 
    if (FileIn.fail()) {
        cout << "Data update failed!" << endl;
        return false;
    }
    
    while (!FileIn.eof()) {
        Word w;
        i++; 
        FileIn >> w.eng;
        FileIn >> w.type;
        FileIn >> w.meaning;
        //Tòn thêm FileIn ảnh vô đây hỉ
        insertItem(w);
        cout << "--------" << endl;
    }
    this->wordCount = i - 1;
    FileIn.close();
    return true;
}
void HashTable::printTable() {
    for (int i; i < hashGroups; i++) {
        cout << i;
		
        for (auto x: table[i]) {
            cout << "---> ";
            x.display();
        }
        cout << endl;
    }
    return;
}

int to_continue() {
	char yes;
	printf("\n\nPress y to continue!\nPress b to back to menu!\nPress any key to exit!\nInput: ");
	fflush(stdin);
	yes = getchar();
	if (yes == 'y')
		return 1;
	else if (yes == 'b')
		return 2;
    return 2;
}

















