#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> umap;
        for(char &ch: s){
            umap[ch]=umap[ch]+1;
        }
        for(int i=0;i<s.size();i++){
            if(umap[s[i]]==1) return i;
        }
        return -1;
    }
};