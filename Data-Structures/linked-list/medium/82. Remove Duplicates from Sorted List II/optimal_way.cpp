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
        ListNode* temp=head, **dPointer=&(head);
        while(temp){
            if(temp->next && temp->val==temp->next->val){
                while(temp->next && temp->val==temp->next->val) temp=temp->next;
            }
            else{
                *dPointer=temp;
                dPointer=&(temp->next);
            }
            temp=temp->next;
        }
        *dPointer=nullptr;
        return head;
    }
};