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
    ListNode* swapPairs(ListNode* head) {
        ListNode **ptr=&head, *node1, *node2;
        while((node1=*ptr) && (node2=node1->next)){
            node1->next=node2->next;
            node2->next=node1;
            *ptr=node2;
            ptr=&(node1->next);
        }
        return head;
    }
};