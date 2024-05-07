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
ListNode* list2;
    void funct(ListNode* head, ListNode* middle){
        if(head==middle) return;
        funct(head->next, middle);
        ListNode* ref=list2->next;
        list2->next=head->next;
        head->next=list2;
        list2=ref;
    }
    
    void reorderList(ListNode* head) {
        if(head->next==nullptr) return;
        ListNode* slow=head, *fast=head->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        list2=slow->next;
        slow->next=nullptr;
        if(fast){
            slow=slow->next; // slow will be nullptr.
            // this is for the even-no of nodes in an linked-list case.
        }
        funct(head, slow);
    }
};