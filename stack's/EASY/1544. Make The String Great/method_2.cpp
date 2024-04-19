#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string temp="";
        for(char &ch: s){
            if(temp!="" && abs((int)(ch-temp.back()))==32){
                temp.pop_back();
                continue;
            }
            temp.push_back(ch);
        }
        return temp;
    }
};