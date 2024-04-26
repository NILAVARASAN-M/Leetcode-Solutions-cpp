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

// RECURSION.

class Solution {
public:
ListNode* global=nullptr;
int i=0;
void funct(ListNode* head, int k){
    if(head==nullptr){
        return;
    }
    funct(head->next, k);
    if(i==(k-1)){
        swap(head->val, global->val);
    }
    global=global->next;
    i++;
    return;
}
    ListNode* swapNodes(ListNode* head, int k) {
        global=head;
        funct(head, k);
        return head;
    }
};