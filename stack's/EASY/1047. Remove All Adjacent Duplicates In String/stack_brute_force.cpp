#include<bits/stdc++.h>

using  namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sta;
        while(!s.empty()){
            if(!sta.empty() && sta.top()==s[0]){
                sta.pop();
                s.erase(s.begin());
                continue;
            }
            sta.push(s[0]);
            s.erase(s.begin());
        }
        while(!sta.empty()){
            s=sta.top()+s;
            sta.pop();
        }
        return s;
    }
};