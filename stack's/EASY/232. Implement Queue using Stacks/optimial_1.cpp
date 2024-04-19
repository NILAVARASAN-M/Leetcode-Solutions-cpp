#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> input;
    stack<int> output;
    int top=0;
public:
    MyQueue() {}

    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int val=output.top();
            output.pop();
            return val;
        }
        if(!input.empty()){
             while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return pop();
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        if(!input.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        return peek();
    }
    
    bool empty() {
        return input.empty() && output.empty();
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