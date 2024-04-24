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
    vector<int> vect;
    stack<int> sta;
    vector<int> nextLargerNodes(ListNode* head) {
        if(head==nullptr){
            return vect;
        }
        nextLargerNodes(head->next);
        while(!sta.empty() && head->val>=sta.top()){
            sta.pop();
        }
        vect.insert(vect.begin(), (sta.empty())? 0: sta.top());
        sta.push(head->val);
        return vect;
    }
};