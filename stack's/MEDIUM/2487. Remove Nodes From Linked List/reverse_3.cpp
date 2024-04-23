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
    ListNode* reverse(ListNode* current, ListNode* prev=nullptr){
        while(current){
            swap(current->next, prev);
            swap((prev)? prev->next: prev, current);
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        head=reverse(head);
        for(ListNode* temp=head; temp!=nullptr && temp->next!=nullptr; ){
            if(temp->val>temp->next->val){
                temp->next=temp->next->next;
            }
            else{
                temp=temp->next;
            }
        }
        return reverse(head);
    }
};