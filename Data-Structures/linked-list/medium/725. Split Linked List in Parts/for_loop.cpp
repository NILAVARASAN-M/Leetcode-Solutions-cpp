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

        int base_len=length/k, rem=length%k;
        vector<ListNode*> vect;
        ListNode *prev;

        for(int i=0;i<k;i++){
            if(head==nullptr){
                vect.push_back(nullptr);
                continue;
            }

            int count=base_len+((rem>0)? 1:0);
            rem--;
            vect.push_back(head);
            for(int j=0;j<count && head;j++){
                prev=head;
                head=head->next;
            }
            prev->next=nullptr;
        }

        return vect;
    }
};