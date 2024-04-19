#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> umap;
        umap[')']='(';
        umap['}']='{';
        umap[']']='[';
        stack<char> sta;
        for(auto &val: s){
            if(umap.count(val)==0){
                sta.push(val);
            }
            else{
                if(sta.empty()){
                    return false;
                }
                if(umap[val]!=sta.top()){
                    return false;
                }
                sta.pop();
            }
        }
        return sta.empty();
    }
};