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
        string binary="";
        while(head){
            binary+=to_string(head->val);
            head=head->next;
        }
        return stoi(binary, nullptr, 2); // the string will be converted to an decimal, 2 tells that the values is of type 
        // binary, and while calculating if any remaining characters will be replaced with nullptr.
    }
};