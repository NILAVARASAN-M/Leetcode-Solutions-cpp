#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> res(n);
        for(int i=n-1;i>=0;i--){
            int j=i+1;
            while(j<n && temperatures[j]<=temperatures[i]){
                if(res[j]>0){
                    j=res[j]+j;
                }
                else{
                    j=n;
                }
            }
            res[i]=(j==n)? 0:j-i; 
        }
        return res;
    }
};

// 