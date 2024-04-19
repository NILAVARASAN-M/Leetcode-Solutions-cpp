#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minLength(string s) {
        stack<char> sta;
        while(!s.empty()){
            if(!sta.empty() && ((sta.top()=='A' && s[0]=='B') || (sta.top()=='C' && s[0]=='D')) )
            {
                sta.pop();
                s.erase(s.begin());
            }
            else{
                sta.push(s[0]);
                s.erase(s.begin());
            }
        }
        return sta.size();
    }
};