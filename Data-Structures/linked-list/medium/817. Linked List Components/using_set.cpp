#include<bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());

        int count=0, streak=0;
        for(; head!=nullptr; head=head->next){
            if(uset.count(head->val)){
                count+=!streak;
                streak=true;
            }
            else{
                streak=false;
            }
        }
        return count;
    }
};