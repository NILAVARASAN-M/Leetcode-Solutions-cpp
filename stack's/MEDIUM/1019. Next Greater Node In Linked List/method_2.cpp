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
        // since we are returning anyway an vector, so we will store in the vector itself.
        vector<int> vect;
        stack<int> sta;
        for(auto p=head; p!=nullptr ; p=p->next) vect.push_back(p->val);
        for(int i=vect.size()-1; i>=0 ; i--){
            int val=vect[i];
            while(!sta.empty() && sta.top()<=vect[i]){
                sta.pop();
            }
            vect[i]=(sta.empty())? 0: sta.top();
            sta.push(val);
        }
        return vect;
    }
};