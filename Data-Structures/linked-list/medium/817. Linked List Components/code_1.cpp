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
        unordered_map<int, int> umap;
        for(int &val: nums){
            umap[val]=0;
        }

        int count=0;
        while(head){
            if(umap.count(head->val)){
                count++;
                while(head && umap.count(head->val)){
                    head=head->next;
                }
                continue;
            }
            head=head->next;
        }
        return count;
    }
};