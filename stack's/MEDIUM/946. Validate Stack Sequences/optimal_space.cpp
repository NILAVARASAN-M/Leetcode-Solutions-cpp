#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i=0, j=0;
        while(i<pushed.size()){
            if(i==0 && pushed[i]==popped[j]){
                j++;
                pushed.erase(pushed.begin());
            }
            else if(i==0 && pushed[i]!=popped[j]){
                i++;
            }
            else if(i>0 && pushed[i]==popped[j]){
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