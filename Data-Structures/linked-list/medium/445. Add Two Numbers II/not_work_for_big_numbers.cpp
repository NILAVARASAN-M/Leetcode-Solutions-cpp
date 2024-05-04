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
        long long sum1=0, sum2=0;
        while(l1){
            sum1=sum1*10+l1->val;
            l1=l1->next;
        }
        while(l2){
            sum2=sum2*10+l2->val;
            l2=l2->next;
        }
        long long sum=sum1+sum2;
        ListNode *current=nullptr;
        do{
            ListNode *temp=new ListNode(sum%10);
            sum=sum/10;
            temp->next=current;
            current=temp;
        }
        while(sum);
        return current;
    }
};