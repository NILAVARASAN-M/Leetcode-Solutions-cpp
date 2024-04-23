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
    ListNode* reverse(ListNode* current){
        ListNode* prev=nullptr;
        while(current){
            swap(current->next, prev);
            swap((prev)? prev->next: prev, current);
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode *res=reverse(head);
        head=res;
        while(res){
            ListNode *temp=res->next;
            while(temp && temp->val<res->val){
                temp=temp->next;
            }
            res->next=temp;
            res=res->next;
        }
        return reverse(head);
    }
};

    // ListNode* reverse(ListNode *current, ListNode *prev=nullptr)
    // {
    //     while(current!=nullptr){
    //         swap(current->next, prev);
    //         swap((prev!=nullptr)? prev->next: prev, current);
    //     }
    //     return prev;
    // }