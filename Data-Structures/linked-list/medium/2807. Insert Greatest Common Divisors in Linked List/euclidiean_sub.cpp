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
    int gcd_sub(int a, int b){
        if(a==0) return b;
        if(b==0) return a;
        if(a==b) return a;
        if(a>b) return gcd_sub(a-b, b);
        return gcd_sub(a, b-a);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp && temp->next){
            int gcd_val=gcd_sub(temp->val, temp->next->val);
            ListNode *node=new ListNode(gcd_val);
            node->next=temp->next;
            temp->next=node;
            temp=temp->next->next;
        }
        return head;
    }
};