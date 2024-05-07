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
        if(!head || !head->next || !head->next->next) return;

        ListNode *lastNode=head;
        while(lastNode->next->next) lastNode=lastNode->next;

        lastNode->next->next=head->next;
        head->next=lastNode->next;

        lastNode->next=nullptr;

        reorderList(head->next->next);
    }
};