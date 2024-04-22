#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    vector<int> vect;
    int i, j, n;
    MyCircularDeque(int k): i(-1), j(-1), vect(k, 0), n(k) {}
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            i=j=0;
            vect[j]=value;
            return true;
        }
        i=(n+i-1)%n;
        vect[i]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            i=j=0;
            vect[j]=value;
            return true;
        }
        j=(j+1)%n;
        vect[j]=value;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        if(i==j){
            i=j=-1;
            return true;
        }
        i=(i+1)%n;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        if(i==j){
            i=j=-1;
            return true;
        }
        j=(n+j-1)%n;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return vect[i];
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return vect[j];
    }
    
    bool isEmpty() {
        if(i==-1 && j==-1) return true;
        return false;
    }
    
    bool isFull() {
        if((i)==(j+1)%n) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */