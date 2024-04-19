#include<bits/stdc++.h>
using namespace std;

struct For_arr{
    int num;
    int min_num;
    For_arr(int val1, int val2): num(val1), min_num(val2){}
};

class MinStack {
public:
    vector<For_arr> vect;
    int minval=numeric_limits<int>::max();
    void push(int val) {
        minval=min(minval, val);
        For_arr obj(val, minval);
        vect.push_back(obj);
    }
    
    void pop() {
        vect.pop_back();
        minval=(vect.empty())? numeric_limits<int>::max() : (vect.back()).min_num; 
    }
    
    int top() {
        return  (vect.back()).num;
    }
    
    int getMin() {
        return  (vect.back()).min_num;
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

