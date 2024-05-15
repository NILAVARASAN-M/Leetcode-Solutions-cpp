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
    ListNode* funct(ListNode* head, ListNode* target){
        if(head==target) return target;
        ListNode *temp=funct(head->next, target);
        if(head->val<=temp->val) return head;
        swap(head->val, temp->val);
        return head;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode *temp=head->next;
        while(temp){
            funct(head, temp);
            temp=temp->next;
        }
        return head;
    }
};