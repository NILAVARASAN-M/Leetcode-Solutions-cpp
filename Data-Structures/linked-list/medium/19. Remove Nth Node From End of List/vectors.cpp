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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> vect;
        ListNode* temp=head;
        while(temp){
            vect.push_back(temp);
            temp=temp->next;
        }
        vect.push_back(nullptr);
        int l=vect.size();
        if((l-1)==n){
            return head->next;
        }
        vect[l-n-2]->next=vect[l-n-1]->next;
        return head;
    }
};