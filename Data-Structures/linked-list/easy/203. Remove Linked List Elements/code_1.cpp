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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* temp=new ListNode(-1);
        temp->next=head;
        head=temp;
        ListNode* prev=head;
        while(temp){
            if(temp->val==val){
                prev->next=temp->next;
                temp=prev->next;
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head->next;
    }
};