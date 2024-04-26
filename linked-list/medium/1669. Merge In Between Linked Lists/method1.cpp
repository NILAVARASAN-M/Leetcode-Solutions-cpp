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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // now for list-2
        ListNode *l2EndNode=list2;
        while(l2EndNode->next) l2EndNode=l2EndNode->next;

        // now for list-1
        int i=0;
        ListNode *nodeA, *nodeB;
        for(auto node=list1; node!=nullptr; node=node->next, i++){
            if(i+1==a) {
                nodeA=node;
            }
            else if(i==b){
                nodeB=node; 
                break;
            }
        }
        nodeA->next=list2;
        l2EndNode->next=nodeB->next;
        return list1;
    }
};