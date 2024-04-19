#include<bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> input;
    stack<int> output;
    int top=0;
    MyQueue() {}
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        if(!output.empty()){
            int val=output.top();
            return (output.pop(), val);
        }
        int val=peek();
        return (output.pop(), val);
    }
    
    int peek() {
        if(!output.empty()){
            return output.top();
        }
        while(!input.empty()){
            output.push(input.top());
            input.pop();
        }
        return output.top();
    }
    
    bool empty() {
        return input.empty() && output.empty();
    }
};