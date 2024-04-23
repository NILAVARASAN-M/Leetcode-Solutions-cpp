#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> vect(temperatures.size());
        stack<int> sta;
        for(int i=0;i<temperatures.size(); i++){
            while(!sta.empty() && temperatures[i]>temperatures[sta.top()]){
                int val=i-sta.top();
                vect[sta.top()]=val;
                sta.pop();
            }
            sta.push(i);
        }
        return vect;
    }
};