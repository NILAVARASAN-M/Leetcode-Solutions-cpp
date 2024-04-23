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
    ListNode* removeNodes(ListNode* temp) {
        stack<ListNode*> sta;
        while(temp){
            while(!sta.empty() && sta.top()->val<temp->val){
                sta.pop();
            }
            sta.push(temp);
            temp=temp->next;
        }
        temp=nullptr;
        while(!sta.empty()){
            sta.top()->next=temp;
            temp=sta.top();
            sta.pop();
        }
        return temp;
    }
};