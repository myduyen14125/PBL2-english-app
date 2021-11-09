// CPP program to implement hashing with chaining
#include <bits/stdc++.h>
#include "word.cpp"
using namespace std;

class Hash
{
    friend class word;
    int BUCKET; // No. of buckets
    // Pointer to an array containing buckets
    list<int> *table;

public:
    Hash(int V); // Constructor
    void insertItem(int x);
    void deleteItem(int key);
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }
    void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (index)th list
    list<int>::iterator i;
    for (i = table[index].begin();
         i != table[index].end(); i++)
    {
        if (*i == key)
            break;
    }

    // if key is found in hash table, remove it
    if (i != table[index].end())
        table[index].erase(i);
}

// function to display hash table
void Hash::displayHash()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

// Driver program
int main()
{   
    int size, a[1000]; 
    Word w;
    cout << "Nhap so tu: "; 
        cin >> size;
    for(int i = 0; i < size; i++) {
        w.inputWord();
        a[i] = w.genKey();
        cout << a[i];
    }
    cout << endl;
    // array that contains keys to be mapped
    int n = size;

    // insert the keys into the hash table
    Hash h(8); // 7 is count of buckets in
               // hash table
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    // display the Hash table
    h.displayHash();

    return 0;
}
