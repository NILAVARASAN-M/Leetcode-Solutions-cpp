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
    int getDecimalValue(ListNode* head) {
        int length=-1;
        ListNode *temp=head;
        while(temp){
            length++;
            temp=temp->next;
        }
        int sum=0;
        while(length!=-1){
            sum+=head->val*pow(2, length);
            length--;
            head=head->next;
        }
        return sum;
    }
};