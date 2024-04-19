#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        stack<int> sta;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!sta.empty() && sta.top()<=nums2[i]){
                sta.pop();
            }
            umap[nums2[i]]=(sta.empty())? -1:sta.top();
            sta.push(nums2[i]);
        }
        for(int i=0;i<nums1.size(); i++){
            nums1[i]=umap[nums1[i]];
        }
        return nums1;
    }
};