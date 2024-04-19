#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0;
        while(i<(int)pushed.size()){  // this part why we have typcasted the size_t to integer????, for this question go the typecast_comp.cpp
        // there i explanied why. we have to typecast and what will happen if we dont type-cast.
            if(i>=0 && pushed[i]==popped[j]){
                pushed.erase(pushed.begin()+i);
                j++;
                i-=1;
            }
            else{
                i++;
            }
        }
        return pushed.empty();
    }
};

// 