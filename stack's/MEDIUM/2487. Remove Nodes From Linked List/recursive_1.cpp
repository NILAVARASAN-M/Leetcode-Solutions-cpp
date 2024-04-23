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
    ListNode* removeNodes(ListNode* head) {
        if(head->next==nullptr){
            return head;
        }
        ListNode *temp=removeNodes(head->next);
        if(head->val<temp->val) return temp;
        head->next=temp;
        return head;
    }
};