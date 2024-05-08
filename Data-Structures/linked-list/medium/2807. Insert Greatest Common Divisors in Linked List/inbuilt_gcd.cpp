#include<bits/stdc++.h>
#include<numeric>
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
    
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        while(temp && temp->next){
            ListNode *node=new ListNode(std::__gcd(temp->val, temp->next->val));
            node->next=temp->next;
            temp->next=node;
            temp=temp->next->next;
        }
        return head;
    }
};