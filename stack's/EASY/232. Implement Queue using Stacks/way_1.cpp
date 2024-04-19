#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> sta1;
    stack<int> sta2;
    int top;
public:
    MyQueue() : top(0){ 
    }
    
    void push(int x) {
        if(sta1.empty()){
            top=x;
        }
        sta1.push(x);
    }
    
    int pop() {
        while(!sta1.empty()){
            sta2.push(sta1.top());
            sta1.pop();
        }
        int val=sta2.top();
        sta2.pop();
        while(!sta2.empty()){
            push(sta2.top());
            sta2.pop();
        }
        return val;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return sta1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */