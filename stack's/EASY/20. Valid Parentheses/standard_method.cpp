#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        for(char &val: s){
            if(val=='(' || val=='{' || val=='['){
                sta.push(val);
            }
            else{
                if(sta.empty()){
                    return false;
                }
                if(val==']' && sta.top()!='['){
                    return false;
                }
                else if(val==')' && sta.top()!='('){
                    return false;
                }
                else if(val=='}' && sta.top()!='{'){
                    return false;
                }
                sta.pop();
            }
        }
        return sta.empty();
    }
};