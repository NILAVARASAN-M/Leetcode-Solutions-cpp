#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices);
        stack<int> sta;
        for(int i=prices.size()-1;i>=0;i--){
            while(!sta.empty() && sta.top()>prices[i]){
                sta.pop();
            }
            res[i]=(sta.empty())? res[i]: res[i]-sta.top();
            sta.push(prices[i]);
        }
        return res;
    }
};