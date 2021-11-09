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
        friend class Word;
        HashTable(int b = 7); //default constructor

        bool isEmpty() const;
        int hashFunction(int key);

        void insertItem(Word w);
        void removeItem(int key);
        void searchTable(string eng);

        void readFile();
        void printTable();
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
    
    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
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
	if (yes == 'b')
		return 2;
}

int main() {
    HashTable HT;
    int n;
    cout << "Nhập số từ: "; cin >> n; 
    for (int i = 0; i < n; i++) {
        Word w;
        w.inputWord();
        HT.insertItem(w); //Chức năng chèn từ ở đây nè
        cout << "-----" << endl;
    }

    //View dictionary
    HT.printTable();

    //Edit dictionany nè 
    /*Chức năng xóa 1 từ trong từ điển nè, có chi Tòn xóa cmt để chạy nghe hhaha*/
    // cout << "Nhập key của từ cần xóa: "; 
    // int key; cin >> key;
    // HT.removeItem(key);
    // cout << "-----" << endl;
    // HT.printTable();

    /*Play game qua class khác nè*/

    return 0;
}

















