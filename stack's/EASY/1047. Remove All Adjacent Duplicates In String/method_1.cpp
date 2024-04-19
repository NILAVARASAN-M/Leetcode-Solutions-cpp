#include<bits/stdc++.h>

using  namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        int index=0;
        while(index<s.size()){
            if(index>0 && s[index]==s[index-1]){
                s.replace(index-1, 2, "");
                index--;
                continue;
            }
            index++;
        }  
        return s;
    }
};