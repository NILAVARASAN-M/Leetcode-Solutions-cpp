#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> vect(n, -1);
        stack<int> sta;
        for(int i=2*n-1;i>=0;i--){
            while(!sta.empty() && sta.top()<=nums[i%n]){
                sta.pop();
            }
            if(i<n){
                vect[i]=(sta.empty())? -1: sta.top();
            }
            sta.push(nums[i%n]);
        }
        return vect;
    }
};