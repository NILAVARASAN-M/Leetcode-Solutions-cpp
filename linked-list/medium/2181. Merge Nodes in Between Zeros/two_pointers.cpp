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
        ListNode* node1=head->next, *node2=head;
        int sum=0;

        while(node1){
        if(node1->val==0){
            node2->val=sum;
            if(node1->next){
                node2=node2->next;
            }
            sum=0;
        }
        else{
            sum+=node1->val;
        }
        node1=node1->next;
        }
        node2->next=nullptr;
        return head;
    }
};