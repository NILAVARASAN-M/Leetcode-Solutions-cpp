#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int i=0;
        for(int j=0;j<s.size(); j++, i++){
            s[i]=s[j];
            if(s[i]=='*'){
                i-=2;
            }
        }
        return s.substr(0, i);
    }
};