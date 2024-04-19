#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> index;
        int i=0;
        for(int j=0;j<s.size();j++, i++){
            s[i]=s[j];
            if(s[i]=='('){
                index.push(i);
            }
            else if(s[i]==')'){
                if (index.empty()) {
                    i-=1;
                }
                else{
                    index.pop();
                }
            }
        }
        s=s.substr(0, i);
        while(!index.empty()){
            s.erase(index.top(), 1);
            index.pop();
        }
        return s;
    }
};