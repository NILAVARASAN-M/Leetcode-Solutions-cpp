// this is the standard method used for solving this problem.

#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<long long> sta;
    long long minV=std::numeric_limits<int>::max();

    void push(int val) {
        if(val==min((int)minV, val)){
            long long calc=(long long)2*val-minV;
            sta.push(calc);
            minV=val;
        }
        else{
            sta.push(val);
        }
    }
    
    void pop() {
        if(sta.top()<minV){
            minV=2*minV-sta.top();
            sta.pop();
        }
        else{
            sta.pop();
        }
    }
    
    int top() {
        if(sta.top()<minV){
            return minV;
        }
        return sta.top();
    }
    
    int getMin() {
        return minV;
    }
};
