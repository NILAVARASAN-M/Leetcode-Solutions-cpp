#include<bits/stdc++.h>
using namespace std;

class MyCircularDeque {
public:
    queue<int> q;
    int cap;
    MyCircularDeque(int k): cap(k){}
    
    bool insertFront(int value) {
        if(q.size()==cap) return false;
        q.push(value);
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
        return true;
    }
    
    bool insertLast(int value) {
        if(q.size()==cap) return false;
        q.push(value);
        return true;
    }
    
    bool deleteFront() {
        if(q.size()==0) return false;
        q.pop();
        return true;
    }
    
    bool deleteLast() {
        if(q.size()==0) return false;
        for(int i=0;i<q.size()-1;i++){
            q.push(q.front());
            q.pop();
        }
        q.pop();
        return true;
    }
    
    int getFront() {
        if(q.empty()) return -1;
        return q.front();
    }
    
    int getRear() {
        if(q.empty()) return -1;
        return q.back();
    }
    
    bool isEmpty() {
        return q.empty();
    }
    
    bool isFull() {
        return q.size()==cap;
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