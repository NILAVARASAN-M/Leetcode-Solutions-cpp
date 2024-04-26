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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *temp1=new ListNode(-1);
        ListNode* temp2=temp1;
        head=head->next;
        int count=0;
        while(head){
            if(head->val==0){
                temp1->next=new ListNode(count);
                temp1=temp1->next;
                count=0;
            }
            else{
                count+=head->val;
            }
            head=head->next;
        }
        return temp2->next;
    }
};