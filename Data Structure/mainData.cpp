#include <iostream>
#include <fstream>
#include "hashTable.cpp"
using namespace std;

int main() {
    HashTable HT;
    HT.readFile();

    // for (int i = 0; i < 3; i++) {
    //     cout << "Nhập từ: " << endl;
    //     Word w;
    //     cin >> w.eng;
    //     cin >> w.type;
    //     cin >> w.meaning;
    //     HT.insertItem(w);
    //     cout << "--------" << endl;
    // }

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

