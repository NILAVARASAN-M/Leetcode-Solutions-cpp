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
    int count(ListNode* node){
        if(node==nullptr){
            return 0;
        }
        return count(node->next)+1;
    }

    int rec_fn(ListNode *node1, ListNode *node2, int diff){
        if(node1==nullptr){
            return 0;
        }
        if(diff){
            int value=rec_fn(node1->next, node2, --diff);
            value+=node1->val;
            node1->val=value%10;
            return value/10;
        }
        int value=rec_fn(node1->next, node2->next, diff);
        value=value+node1->val+node2->val;
        node1->val=value%10;
        return value/10;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=count(l1);
        int len2=count(l2);
        if(len2>len1){
            ListNode *temp=l2;
            l2=l1;
            l1=temp;
        }
        int num=rec_fn(l1, l2, abs(len2-len1));
        if(num==0) return l1;
        ListNode *temp=new ListNode(num);
        temp->next=l1;
        return temp;
    }
};