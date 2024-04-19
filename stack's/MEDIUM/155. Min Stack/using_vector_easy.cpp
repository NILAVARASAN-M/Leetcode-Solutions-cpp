#include<bits/stdc++.h>
using namespace std;

class MinStack {
public:
    vector<pair<int, int>> vect;
    int Min=numeric_limits<int>::max();
    void push(int val) {
        Min=min(val, Min);
        vect.push_back(make_pair(val, Min));
    }
    
    void pop() {
        vect.pop_back();
        Min=(vect.empty())? numeric_limits<int>::max() : vect.back().second;
    }
    
    int top() {
        return vect.back().first;
    }
    
    int getMin() {
        return vect.back().second;
    }
};