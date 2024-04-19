#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int i=-1;
        for(char &val: s){
            if(val=='(' || val=='{' || val=='['){
                s[++i]=val;
            }
            else{
                if(i==-1){
                    return false;
                }
                if((val==')' && s[i]=='(') || (val==']' && s[i]=='[') || (val=='}' && s[i]=='{')){
                    i--;
                }
                else{
                    return false;
                }
            }
        }
        return i==-1;
    }
};