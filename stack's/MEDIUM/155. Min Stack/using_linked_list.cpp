#include<bits/stdc++.h>

using namespace std;

struct Node{
    int num;
    int min_num;
    Node *next;
    Node(int val) : num(val), next(nullptr), min_num(0) {}
};


class MinStack {
public:
    Node *head=nullptr;
    int minval=numeric_limits<int>::max();

    MinStack() {}
    
    void push(int val) {
        Node* temp=new Node(val);
        minval=min(val, minval);
        temp->min_num=minval;
        temp->next=head;
        head=temp;
    }
    
    void pop() {
        Node *temp=head;
        head=head->next;
        minval=(head)? head->min_num: numeric_limits<int>::max();
        delete temp;
    }
    
    int top() {
        return head->num;
    }
    
    int getMin() {
        return head->min_num;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */