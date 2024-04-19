#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=-1, j=-1;
        for(char &val: s){
            if(val=='#' && i!=-1){
                i--;
            }
            else if(val!='#'){
                s[++i]=val;
            }
        }
        for(char &val: t){
            if(val=='#' && j!=-1){
                j--;
            }
            else if(val!='#'){
                t[++j]=val;
            }
        }
        return s.substr(0, i+1)==t.substr(0, j+1);
    }
};