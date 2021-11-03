#include<iostream>
#include<list>  //STL
#include "word.cpp"
#include<cstring>
using namespace std;

class HashTable {
    private: 
        int hashGroups;
        list<pair<int, string>> *table;
    public:
        HashTable(int b = 7); //default constructor
        bool isEmpty() const;
        int genKey(string word);
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

HashTable::HashTable(int b) {
    this->hashGroups = b;
    table = new list<pair<int, string>>[hashGroups];
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
void HashTable::insertItem(int key, string value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true; 
            bItr->second = value;
            cout << "[Warn] - Key exist. Value replaced" << endl;
            break;
        }
    }
    if (!keyExists) {
        cell.emplace_back(key, value);
    }
    return;
}
void HashTable::removeItem(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell); bItr++) {
        if (bItr->first == key) {
            keyExists = true; 
            bItr = cell.erase(bItr);
            cout << "[Info] - Pair removed" << endl;
            break;
        }
    }
    if (!keyExists) {
        cout << "[Warn] - Key not found. Pair not  removed" << endl;
    }
    return;
}
void HashTable::printTable() {
    for (int i; i < hashGroups; i++) {
        cout << i;
        // if (table[i].size() == 0) continue;

        
        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "---> key: " << bItr->first << " Value: " << bItr->second;
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
        HT.insertItem(w.genKey(), w.getEng());
    }

    HT.printTable();

    // HT.removeItem(905);
    // HT.printTable();
    return 0;
}

















