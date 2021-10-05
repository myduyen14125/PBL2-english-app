#include<iostream>
#include<list>  //STL
#include<cstring>
using namespace std;

class HashTable {
    private: 
        static const int hashGroups = 26;
        list<pair<int, string>> table[hashGroups];
    public:
        bool isEmpty() const;
        int hashFunction(int key);
        void insertItem(int key, string value);
        void removeItem(int key);
        string searchTable(int key);
        void printTable();
};

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
    for (int i{}; i < hashGroups; i++) {
        if (table[i].size() == 0) continue;

        auto bItr = table[i].begin();
        for (; bItr != table[i].end(); bItr++) {
            cout << "[Info] key: " << bItr->first << " Value: " << bItr->second << endl;
        }
    }
    return;
}

int main() {
    HashTable HT;

    if (HT.isEmpty()) {
        cout << "Empty! " << endl;
    }
    else {
        cout << "Oh no! Not empty"<< endl;
    }
    HT.insertItem(905, "Hehe");
    HT.insertItem(915, "Hehe1");
    HT.insertItem(105, "Hehe2");
    HT.insertItem(405, "Hehe3");
    HT.insertItem(968, "Hehe4");
    HT.insertItem(368, "Hehe5");
    HT.insertItem(247, "Hehe6");

    HT.printTable();

    HT.removeItem(905);
    HT.printTable();
    return 0;
}

















