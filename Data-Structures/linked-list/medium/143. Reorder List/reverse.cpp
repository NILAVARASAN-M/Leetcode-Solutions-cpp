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
    void reorderList(ListNode* head) {
        ListNode *slow=head, *fast=head->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode *list2=slow->next;
        slow->next=nullptr;

        list2=reverse(list2);
        fast=head;
        while(list2){
            ListNode *temp1=list2->next;
            ListNode *temp2=fast->next;
            list2->next=fast->next;
            fast->next=list2;
            fast=temp2;
            list2=temp1;
        }
    }
    ListNode *reverse(ListNode* current, ListNode* prev=nullptr){
        while(current){
            swap(current->next, prev);
            swap((prev)? prev->next: prev, current);
        }
        return prev;
    }
};

