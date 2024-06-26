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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* temp=deleteDuplicates(head->next);
        if(head->val==temp->val){
            return temp;
        }
        head->next=temp;
        return head;
    }
};