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
        ListNode* temp1=head, *temp2=nullptr, *temp3=head;
        for(int i=0;i<k-1;i++){
            temp1=temp1->next;
        }
        temp2=temp1;
        temp1=temp1->next;
        while(temp1){
            temp1=temp1->next;
            temp3=temp3->next;
        }
        swap(temp2->val, temp3->val);
        return head;
    }
};