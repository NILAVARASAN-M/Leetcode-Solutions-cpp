#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        stack<int> sta;
        for(int i=0;i<nums2.size();i++){
            while(!sta.empty() && nums2[i]>nums2[sta.top()]){
                umap[nums2[sta.top()]]=nums2[i];
                sta.pop();
            }
            sta.push(i);
        }
        vector<int> vect;
        for( int &val: nums1){
            vect.push_back(umap.count(val)? umap[val]: -1);
        }
        return vect;
    }
};