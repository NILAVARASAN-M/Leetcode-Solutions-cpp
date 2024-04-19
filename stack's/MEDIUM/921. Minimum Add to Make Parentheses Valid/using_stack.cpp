#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> sta;
        int count=0;
        for(char &val: s){
            if(val=='('){
               sta.push('(');
            }
            else{
                if(sta.empty()) count++;
                else sta.pop();
            }
        }
        return count+sta.size();
    }
};