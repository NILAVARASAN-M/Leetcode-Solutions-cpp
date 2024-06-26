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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head, *fast=head;
        ListNode* prev=nullptr;
        while(fast && fast->next){
            fast=fast->next->next;
            ListNode* current=slow;
            slow=slow->next;
            current->next=prev;
            prev=current;
        }

        if(fast){
            slow=slow->next;
        }
        while(slow){
            if(slow->val!=prev->val) return false;
            slow=slow->next;
            prev=prev->next;
        }
        return true;
    }
};