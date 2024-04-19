#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sta;
        int j=0;
        for(int i=0;i<pushed.size();i++){
            sta.push(pushed[i]);
            while(!sta.empty() && sta.top()==popped[j]){
                sta.pop();
                j++;
            }
        }
        return sta.empty();
    }
};