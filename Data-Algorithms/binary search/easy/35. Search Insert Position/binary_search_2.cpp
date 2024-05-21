#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size()-1;
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};

int searchInsert(vector<int>& nums, int target) {
        int low=0, high=nums.size();
        while(low<=high){
            int mid=(high+low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }