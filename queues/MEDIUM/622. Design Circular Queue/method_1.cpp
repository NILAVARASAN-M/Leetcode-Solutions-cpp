#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    vector<int> vect;
    int front, back, n;
    MyCircularQueue(int k): front(-1), back(-1), n(k), vect(k) {}
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            front=back=0;
            vect[back]=value;
        }
        else{
            back=(back+1)%n;
            vect[back]=value;
        }
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(front==back){
            front=back=-1;
        }
        else{
            front=(front+1)%n;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return vect[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return vect[back];
    }
    
    bool isEmpty() {
        return front==-1 && back==-1;
    }
    
    bool isFull() {
        return front==(back+1)%n;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */