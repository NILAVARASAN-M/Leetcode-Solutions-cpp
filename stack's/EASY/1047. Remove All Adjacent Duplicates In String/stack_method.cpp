#include<bits/stdc++.h>

using  namespace std;


class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> sta;
        for(char &c: s){
            if(sta.size() && sta.top()==c) sta.pop();
            else sta.push(c);
        }
        string res="";
        while(sta.size()){
            res=sta.top()+res;
            sta.pop();
        }
        return res;
    }
};