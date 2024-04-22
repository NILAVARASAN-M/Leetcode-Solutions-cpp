#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vect(26);
        for(char &ch: s){
            vect[ch-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(vect[s[i]-'a']==1) return i;
        }
        return -1;
    }
};