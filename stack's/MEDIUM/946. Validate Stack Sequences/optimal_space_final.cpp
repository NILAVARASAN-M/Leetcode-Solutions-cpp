#include<bits/stdc++.h>
using namespace std;

// this code is the refined one, considering all the typecast_comp.cpp error 
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // two-pointer approach.
        int i=0, j=0;
        while(i<(int)pushed.size()){
            if(i>=0 && pushed[i]==popped[j]){
                pushed.erase(pushed.begin()+i);
                j++;
                i=(i==0)?0:i-1;
            }
            else{
                i++;
            }
        }
        return pushed.empty();
    }
};