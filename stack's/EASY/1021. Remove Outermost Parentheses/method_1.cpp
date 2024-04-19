#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> sta;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                sta.push('(');
                if(sta.size()>1){
                    temp+='(';
                }
            }
            else{
                if(sta.size()==1){
                    sta.pop();
                }
                else{
                    temp+=')';
                    sta.pop();
                }
            }
        }
        return temp;
    }
};