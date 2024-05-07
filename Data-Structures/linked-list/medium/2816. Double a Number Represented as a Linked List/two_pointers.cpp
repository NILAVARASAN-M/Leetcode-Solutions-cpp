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
    ListNode* doubleIt(ListNode* head) {
        ListNode *prev=nullptr , *current=head;
        while(current){
            int val=current->val*2;
            if(val<10){
                current->val=val;
            }
            else if(prev){
                prev->val++;
                current->val=val%10;
            }
            else{
                head=new ListNode(1, head);
                current->val=val%10;
            }
            prev=current;
            current=current->next;
        }
        return head;
    }
};