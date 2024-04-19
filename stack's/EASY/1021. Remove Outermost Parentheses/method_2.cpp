#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int num=0;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                num++;
                if(num>1){
                    temp+='(';
                }
            }
            else{
                if(num==1){
                    num=0;
                }
                else{
                    temp+=')';
                    num--;
                }
            }
        }
        return temp;
    }
};