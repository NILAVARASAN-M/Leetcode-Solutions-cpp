#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        int i=0;
        for(int j=0;j<s.size();j++, i++){
            s[i]=s[j];
            if(i!=0 && abs(s[i]-s[i-1])==32){
                i-=2;
            }
        }
        return s.substr(0,i);
    }
};