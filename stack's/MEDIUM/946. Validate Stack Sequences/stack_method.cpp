#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> sta;
        int i=-1, j=0;
        while(i<(int)pushed.size()){
            if(!sta.empty() && sta.top()==popped[j]){
                j++;
                sta.pop();
                continue;
            }
            i++;
            if(i<pushed.size()){
                sta.push(pushed[i]);
            }
        }
        return sta.empty();
    }
};