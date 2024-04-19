#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int num=0;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') num++;
            else num--;

            if(num==1 && s[i]=='(') continue;
            else if(num==0 && s[i]==')') continue;
            else temp+=s[i];
        }
        return temp;
    }
};