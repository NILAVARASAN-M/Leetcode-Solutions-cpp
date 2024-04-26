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
        ListNode *temp=new ListNode();
        temp->next=head;
        head=temp;
        while(temp && temp->next && temp->next->next){
            ListNode *node1=temp->next;
            ListNode *node2=temp->next->next;
            node1->next=node2->next;
            node2->next=node1;
            temp->next=node2;
            temp=temp->next->next;
        }
        return head->next;
    }
};