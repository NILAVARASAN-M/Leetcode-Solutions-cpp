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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> umap;
        while(headA){
            if(umap.count(headA)) return headA;
            umap[headA]=0;
            headA=headA->next;
        }
        while(headB){
            if(umap.count(headB)) return headB;
            umap[headB]=0;
            headB=headB->next;
        }
        return nullptr;
    }
};