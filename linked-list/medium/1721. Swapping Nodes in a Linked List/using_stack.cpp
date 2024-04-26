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
    ListNode* swapNodes(ListNode* head, int k) {
        stack<ListNode*> sta;

        ListNode* temp=head;
        while(temp){
            sta.push(temp);
            temp=temp->next;
        }
        temp=head;
        for(int i=0;i<k-1;i++){
            temp=temp->next;
            sta.pop();
        }
        int val=sta.top()->val;
        sta.top()->val=temp->val;
        temp->val=val;
        return head;
    }
};