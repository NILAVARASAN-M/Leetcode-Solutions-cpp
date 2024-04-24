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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vect;
        stack<int> sta;
        int count=0;
        while(head){
            while(!sta.empty() && head->val>vect[sta.top()]){
                vect[sta.top()]=head->val;
                sta.pop();
            }
            vect.push_back(head->val);
            sta.push(count++);
            head=head->next;
        }
        while(!sta.empty()){
            vect[sta.top()]=0;
            sta.pop();
        }
        return vect;
    }
};