#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    vector<list<int>> vect;
    int N;

    size_t hash_fn(int key) {
        return key % N;
    }

    list<int>::iterator search(int key) {
        int hash_val = hash_fn(key);
        auto& list = vect[hash_val];
        return find(list.begin(), list.end(), key);
    }

public:
    MyHashSet() : N(10007), vect(10007) {}

    void add(int key) {
        auto& list = vect[hash_fn(key)];
        auto itr = find(list.begin(), list.end(), key);
        if (itr == list.end())
            list.push_back(key);
    }

    void remove(int key) {
        auto& list = vect[hash_fn(key)];
        auto itr = search(key);
        if (itr != list.end())
            list.erase(itr);
    }

    bool contains(int key) {
        auto& list = vect[hash_fn(key)];
        return search(key) != list.end();
    }
};
