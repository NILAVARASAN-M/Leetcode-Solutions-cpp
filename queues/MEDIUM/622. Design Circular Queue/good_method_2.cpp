// this method is really-nice, and quite good method compared to the other methods that i have come far.

#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
private:
    vector<int> vect;
    int headIDX;
    int count_of_elements;
    int size;
public:
    MyCircularQueue(int k) : vect(k), headIDX(0), count_of_elements(0), size(k){}
    
    bool enQueue(int value) {
        if(isFull()) return false;
        int insert_loc=(headIDX+count_of_elements)%size;
        vect[insert_loc]=value;
        count_of_elements++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        headIDX=(headIDX+1)%size;
        count_of_elements--;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return vect[headIDX];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        int index=(headIDX+count_of_elements-1)%size;
        return vect[index];
    }
    
    bool isEmpty() {
        return count_of_elements==0;
    }
    
    bool isFull() {
        return size==count_of_elements;
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