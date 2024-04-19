#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> sta;
    int next(int price) {
        int count=1;
        while(!sta.empty() && sta.top().first<=price){
            count+=sta.top().second;
            sta.pop();
        }
        sta.push(make_pair(price, count));
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */