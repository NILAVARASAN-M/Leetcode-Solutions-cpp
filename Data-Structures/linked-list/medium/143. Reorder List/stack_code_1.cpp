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
        if(head->next==nullptr) return;

        ListNode* slow=head, *fast=head->next;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* list2=slow->next;
        slow->next=nullptr;
        stack<ListNode*> sta;
        while(list2){
            sta.push(list2);
            list2=list2->next;
        }
        fast=head;
        while(!sta.empty() && fast){
            slow=fast->next;
            sta.top()->next=fast->next;
            fast->next=sta.top();
            sta.pop();
            fast=slow;
        }
        return;
    }
};