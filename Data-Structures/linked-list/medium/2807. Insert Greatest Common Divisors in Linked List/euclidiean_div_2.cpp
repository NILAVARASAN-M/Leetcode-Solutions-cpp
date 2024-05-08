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
        return (b==0)? a: gcd_sub(b, a%b);
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