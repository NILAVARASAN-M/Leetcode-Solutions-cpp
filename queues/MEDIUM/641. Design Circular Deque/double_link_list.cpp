#include<bits/stdc++.h>
using namespace std;

struct DNode{
    int val;
    DNode *prev, *next;
    DNode(int num): val(num), prev(nullptr), next(nullptr){}
};

class MyCircularDeque {
public:
    DNode *head, *tail;
    int i, size;
    MyCircularDeque(int k): i(0), size(k) {}
    
    bool insertFront(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            head=tail=new DNode(value);
        }
        else{
            DNode *temp=new DNode(value);
            head->prev=temp;
            temp->next=head;
            head=temp;
        }
        i++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        if(isEmpty()){
            head=tail=new DNode(value);
        }
        else{
            DNode *temp=new DNode(value);
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        i++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        head=head->next;
        i--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        tail=tail->prev;
        i--;
        return true;
    }
    
    int getFront() {
        if(isEmpty()) return -1;
        return head->val;
    }
    
    int getRear() {
        if(isEmpty()) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return i==0 || head==nullptr || tail==nullptr;
    }
    
    bool isFull() {
        return i==size;
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

