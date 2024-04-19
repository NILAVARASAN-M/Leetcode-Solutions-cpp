#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> sta1;
        stack<char> sta2;
        for(char &val: s){
            if(val=='#' && !sta1.empty()){
                sta1.pop();
            }
            else if (val!='#'){
                sta1.push(val);
            }
        }
        for(char &val: t){
            if(val=='#' && !sta2.empty()){
                sta2.pop();
            }
            else if (val!='#'){
                sta2.push(val);
            }
        }
        while(!sta1.empty() && !sta2.empty()){
            if(sta1.top()!=sta2.top()){
                return false;
            }
            sta1.pop();
            sta2.pop();
        }
        return (sta1.size()>0 || sta2.size()>0)? false: true;
    }
};