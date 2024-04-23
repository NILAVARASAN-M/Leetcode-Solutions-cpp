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
        for(ListNode* res=head; res!=nullptr;){
            ListNode* temp=res->next;
            while(temp && res->val>temp->val){
                temp=temp->next;
            }
            res->next=temp;
            res=res->next;
        }
        return reverse(head);
    }
};