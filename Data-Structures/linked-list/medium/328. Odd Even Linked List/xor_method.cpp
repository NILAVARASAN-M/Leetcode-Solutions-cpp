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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even=new ListNode(0);
        ListNode *odd=new ListNode(0);
        ListNode* arr[2]={odd, even};
        for(int i=0; head; i^=1){
            arr[i]=arr[i]->next=head;
            head=head->next;
        }
        arr[0]->next=even->next;
        arr[1]->next=nullptr;
        return odd->next;
    }
};