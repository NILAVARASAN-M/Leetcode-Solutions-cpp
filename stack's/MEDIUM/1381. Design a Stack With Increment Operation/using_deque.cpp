#include<bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    int maS=0;
    deque<int> sta;
    CustomStack(int maxSize) : maS(maxSize), sta() {}
    
    void push(int x) {
        if(sta.size()<maS){
            sta.push_back(x);
        }
    }
    
    int pop() {
        if(sta.empty()){
            return -1;
        }
        int val=sta.back();
        sta.pop_back();
        return val;
    }
    
    void increment(int k, int val) {
        int Min_val=min(k, (int)sta.size());
        for(auto itr=sta.begin(); itr!=(sta.begin()+Min_val); itr++){
            *itr+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */