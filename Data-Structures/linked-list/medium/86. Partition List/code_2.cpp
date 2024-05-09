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
    ListNode* partition(ListNode* head, int x) {
        ListNode* head1=new ListNode(-1);
        ListNode* temp1=head1;
        ListNode* head2=new ListNode(-1);
        ListNode* temp2=head2;

        while(head){
            if(head->val<x){
                temp1->next=head;
                temp1=temp1->next;
            }
            else{
                temp2->next=head;
                temp2=temp2->next;
            }
            head=head->next;
        }

    temp1->next=head2->next;
    temp2->next=nullptr;
    return head1->next;
    }
};