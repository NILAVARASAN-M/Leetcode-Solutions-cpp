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
    ListNode *temp=nullptr;
    bool isPalindrome(ListNode* head) {
        if(head==nullptr){
            return true;
        }
        if(temp==nullptr){
            temp=head;
        }
        bool val=isPalindrome(head->next) && head->val==temp->val;
        temp=temp->next;
        return val;
    }
};