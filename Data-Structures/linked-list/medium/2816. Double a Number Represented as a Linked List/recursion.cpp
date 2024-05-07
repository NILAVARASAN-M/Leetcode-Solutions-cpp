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
    int recursion(ListNode* head){
        if(head==nullptr) return 0;
        int num=recursion(head->next);
        num=num+head->val*2;
        head->val=num%10;
        return num/10;
    }

    ListNode* doubleIt(ListNode* head) {
        if(recursion(head)==1){
            ListNode *temp=new ListNode(1);
            temp->next=head;
            return temp;
        }
        return head;
    }
};