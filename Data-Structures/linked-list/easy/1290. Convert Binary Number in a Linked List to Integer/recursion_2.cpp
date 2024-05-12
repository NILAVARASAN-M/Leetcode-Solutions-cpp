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
    int i=0;
    int getDecimalValue(ListNode* head) {
        if(head->next==nullptr){
            return head->val;
        }
        return getDecimalValue(head->next)+pow(2,++i)*head->val;
    }
};

class Solution2 {
public:
int i=0;
    int getDecimalValue(ListNode* head) {
        return (head->next!=nullptr)?(getDecimalValue(head->next)+head->val*pow(2, ++i)):head->val;
    }
};