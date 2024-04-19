#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        string temp="";
        for(char &val: s){
            if(val=='*') temp.pop_back();
            else temp.push_back(val);
        }
        return temp;
    }
};