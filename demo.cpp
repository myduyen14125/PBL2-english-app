const int P = 1e6 + 3;

struct HashTable {
    vector< pair<int,int> > h[P];

public:
    void insert(int key, int value) {
        int hkey = getHash(key);// lay key
        for (auto p : h[hkey]) {
            if (p.first == key) {
                // key da ton tai trong Hash table, ta bo qua
                return;
            }
        }
        // Them (key, value) vao hash table
        h[hkey].emplace_back(key, value);
    }

    int find(int key) {
        int hkey = getHash(key);
        for(auto p : h[hkey]) {
            if (p.first == key) {
                // ton tai key trong Hash table, return value
                return p.value;
            }
        }
        // Khong tim thay
        return 0;
    }

private:
    int getHash(int key) {
        // Cho 1 key, tra lai Hash value la key % P
        return key % P;
    }
};
