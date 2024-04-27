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
        int num=0;
        ListNode *temp=head;
        while(head) head=head->next, num++;

        vector<ListNode*> vect(k);
        int min_count=num/k;
        int rem=num%k;
        int i=0;
        while(temp){
            int count=min_count+(rem>0? 1: 0);
            rem--;
            ListNode *prev;
            while(count){
                if(vect[i]==nullptr){
                    vect[i]=temp;
                }
                count--;
                prev=temp;
                temp=temp->next;
            }
            prev->next=nullptr;
            i++;
        }
        return vect;
    }
};