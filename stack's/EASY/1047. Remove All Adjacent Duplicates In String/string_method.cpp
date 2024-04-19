#include<bits/stdc++.h>

using  namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string res="";
        for(char &a: s){
            if(res.size() && res.back()==a)
                res.pop_back();
            else
            res.push_back(a);
        }
        return res;
    }
};