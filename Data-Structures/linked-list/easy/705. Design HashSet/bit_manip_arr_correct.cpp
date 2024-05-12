#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    int *num;
public:
    MyHashSet() {
        num=new int[31251];
        // Dynamically allocate memory for the array
        // Initialize the elements (important to avoid undefined behavior)
        for (int i = 0; i < 31251; ++i) {
            num[i] = 0;
        }
    }
    
    void add(int key) {
        num[getIndex(key)]|=getMask(key);
    }
    
    void remove(int key) {
        num[getIndex(key)]&=(~getMask(key));
    }
    
    bool contains(int key) {
        return (num[getIndex(key)]&getMask(key))!=0;
    }

    int getIndex(int key){
        return key/32;
    }
    int getMask(int key){
        key%=32;
        return (1<<key);
    }
};