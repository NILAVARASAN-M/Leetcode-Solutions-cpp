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
    int gcd_brute(int num1, int num2){
        int num=min(num1, num2);
        while(num>0){
            if(num1%num==0 && num2%num==0){
                return num;
            }
            num--;
        }
        return num;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp && temp->next){
            int gcd_val=gcd_brute(temp->val, temp->next->val);
            ListNode *node=new ListNode(gcd_val);
            node->next=temp->next;
            temp->next=node;
            temp=temp->next->next;
        }
        return head;
    }
};