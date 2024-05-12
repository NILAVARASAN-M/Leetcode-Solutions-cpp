#include<bits/stdc++.h>
using namespace std;

class MyHashSet {
private:
    int *num;
public:
    MyHashSet() {
        num=new int[31251];
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

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */