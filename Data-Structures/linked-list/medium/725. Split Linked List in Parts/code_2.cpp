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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        ListNode *temp=head;
        int length=0;
        while(temp) temp=temp->next, length++;

        int base_length=length/k, rem=length%k;
        vector<ListNode*> vect(k);
        int i=0;

        while(head){
            int count=base_length+((rem>0)? 1: 0);
            rem--;
            ListNode *prev;
            while(count){
                if(vect[i]==nullptr){
                    vect[i]=head;
                }
                prev=head;
                head=head->next;
                count--;
            }
            prev->next=nullptr;
            i++;
        }
        return vect;
    }
};