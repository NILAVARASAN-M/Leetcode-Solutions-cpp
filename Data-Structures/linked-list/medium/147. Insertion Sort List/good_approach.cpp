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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *temp=new ListNode();

        ListNode *prev=temp, *for_head=nullptr;
        while(head){
            for_head=head->next;
            while(prev->next!=nullptr && prev->next->val<head->val) prev=prev->next;
            head->next=prev->next;
            prev->next=head;
            prev=temp;
            head=for_head; 
        }
        return temp->next;
    }
};