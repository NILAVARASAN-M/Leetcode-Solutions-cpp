#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> vect(n, -1);
        stack<int> sta;
        for(int i=0;i<2*n-1;i++){
            while(!sta.empty() && nums[sta.top()]<nums[i%n]){
                int val=nums[i%n];
                vect[sta.top()]=val;
                sta.pop();
            }
            sta.push(i%n);
        }
        return vect;
    }
};