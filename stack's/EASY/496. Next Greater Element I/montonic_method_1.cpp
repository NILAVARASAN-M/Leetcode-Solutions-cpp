#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vect(nums2.size(), -1);
        stack<int> sta;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!sta.empty() && sta.top()<=nums2[i]){
                sta.pop();
            }
            vect[i]=(sta.empty())? -1:sta.top();
            sta.push(nums2[i]);
        }

        vector<int> temp(nums1.size());

        for(int i=0;i<nums1.size();i++){
            auto itr=find(nums2.begin(), nums2.end(), nums1[i]);
            int index=itr-nums2.begin();
            temp[i]=vect[index];
        }
        return temp;
    }
};