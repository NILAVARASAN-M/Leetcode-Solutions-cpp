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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int sum=0) {
        if(l1==nullptr && l2==nullptr) {
            return (sum)? new ListNode(1): nullptr;
        }
        if(l1 && l2==nullptr){
            sum+=l1->val;
            l1->val=sum%10;
            sum=sum/10;
            l1->next=addTwoNumbers(l1->next, l2, sum);
            return l1;
        }
        if(l2 && l1==nullptr){
            sum+=l2->val;
            l2->val=sum%10;
            sum=sum/10;
            l2->next=addTwoNumbers(l1, l2->next, sum);
            return l2;
        }
        sum=sum+l2->val+l1->val;
        l1->val=sum%10;
        sum=sum/10;
        l1->next=addTwoNumbers(l1->next, l2->next, sum);
        return l1;
    }
};