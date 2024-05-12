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
    ListNode* temp=nullptr;
    bool Palindrome(ListNode* head) {
        if(head==nullptr){
            return true;
        }
        bool val=Palindrome(head->next);
        val= val && temp->val==head->val;
        return (temp=temp->next, val);
    }
    bool isPalindrome(ListNode* head){
        temp=head;
        return Palindrome(head);
    }
};