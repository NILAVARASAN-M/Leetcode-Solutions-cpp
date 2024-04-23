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
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=new ListNode(numeric_limits<int>::max());
        vector<ListNode*> sta={temp};
        for(ListNode *ptr=head; ptr!=nullptr; ptr=ptr->next){
            while(sta.back()->val<ptr->val){
                sta.pop_back();
            }
            sta.back()->next=ptr;
            sta.push_back(ptr);
        }
        return temp->next;
    }
};