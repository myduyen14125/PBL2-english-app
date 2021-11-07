#include<iostream>
#include<list>  //STL
#include "word.cpp"
#include<cstring>
using namespace std;

class HashTable {
    private: 
        int hashGroups;
        list<Word> *table;
    public:
        HashTable(int b = 7); //default constructor

        bool isEmpty() const;
        int hashFunction(int key);

        void insertItem(Word w);
        void removeItem(int key);
        string searchTable(int key);

        void printTable();
        friend void Word::display();
};

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

int main() {
    HashTable HT;
    int n;
    cout << "Nhap so tu: "; cin >> n; 
    for (int i = 0; i < n; i++) {
        Word w;
        w.inputWord();
        HT.insertItem(w);
        cout << "-----" << endl;
    }

    //View dictionary
    HT.printTable();

    // HT.removeItem(905);
    // HT.printTable();
    return 0;
}

















