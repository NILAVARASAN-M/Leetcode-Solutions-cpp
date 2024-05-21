#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int rec(vector<int> &nums, int target, int low, int high){
        if(low>high) return low;
        int mid=(low+high)/2;
        if(nums[mid]<target){
            return rec(nums, target, mid+1, high);
        }
        return rec(nums, target, low, mid-1);
    }
    int searchInsert(vector<int>& nums, int target) {
        return rec(nums,target, 0, nums.size()-1);
    }
};