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
        if(head==nullptr) return nullptr;
        ListNode *odd=head, *even=head->next, *final_join=head->next;
        while(even && even->next){
            odd=odd->next=odd->next->next;
            even=even->next=even->next->next;
        }
        odd->next=final_join;
        return head;
    }
};