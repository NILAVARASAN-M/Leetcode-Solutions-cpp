#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        string temp="";
        int count=0;
        for(char &val: s){
            if(val=='('){
                temp+='(';
            }
            else{
                if(temp.empty()) count++;
                else temp.pop_back();
            }
        }
        return count+temp.size();
    }
};