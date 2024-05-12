#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
    private:
    vector<bool> vect;
public:
    MyHashSet(): vect(1e6+1, false) {}
    
    void add(int key) {
        vect[key]=true;
    }
    
    void remove(int key) {
        vect[key]=false;
    }
    
    bool contains(int key) {
        return vect[key];
    }
};