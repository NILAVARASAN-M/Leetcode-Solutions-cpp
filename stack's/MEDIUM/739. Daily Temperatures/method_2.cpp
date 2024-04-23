#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> vect(n);
        stack<int> sta;
        for(int i=n-1;i>=0;i--){
            while(!sta.empty() && temperatures[i]>=temperatures[sta.top()]){
                sta.pop();
            }
            vect[i]=(sta.empty())? 0: sta.top()-i;
            sta.push(i);
        }
        return vect;
    }
};