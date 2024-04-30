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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr) return head;
        ListNode *current=head->next, *prev=head, *node1=head;
        int count=0;
        while(current){
            if(count%2==1){
                prev->next=current->next;
                current->next=node1->next;
                node1->next=current;
                node1=node1->next;
                current=prev->next;
            }
            else{
                prev=current;
                current=current->next;
            }
            count++;
        }
        return head;
    }
};