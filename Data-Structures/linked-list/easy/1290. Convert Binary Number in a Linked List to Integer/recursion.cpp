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
        if(head==nullptr) return 0;
        int sum=getDecimalValue(head->next);
        sum+=head->val*pow(2, i);
        i++;
        return sum;
    }
};