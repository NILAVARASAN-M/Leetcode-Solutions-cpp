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
    ListNode* reverse(ListNode* current, ListNode* prev=nullptr){
        while(current){
            swap(current->next, prev);
            swap((prev)? prev->next: prev, current);
        }
        return prev;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        head=reverse(head);
        stack<int> sta;
        vector<int> vect;
        while(head){
            while(!sta.empty() && head->val>=sta.top()){
                sta.pop();
            }
            vect.insert(vect.begin(), (sta.empty())? 0: sta.top());
            sta.push(head->val);
            head=head->next;
        }
        return vect;
    }
};