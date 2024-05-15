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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {        
        int sum=0;
        ListNode *temp=new ListNode(0);
        ListNode *head=temp;
        while(l1 || l2 || sum){
            temp->next=new ListNode(0);
            temp=temp->next;
            if(l1){
                temp->val=l1->val;
                l1=l1->next;
            }
            if(l2){
                temp->val+=l2->val;
                l2=l2->next;
            }
            temp->val+=sum;
            sum=temp->val/10;
            temp->val=temp->val%10;
        }
        return head->next;
    }
};