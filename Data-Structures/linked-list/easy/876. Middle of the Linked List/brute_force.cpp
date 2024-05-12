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
 
// rabbit and turtle problem , this is the standard approach we should always follow.
// example logic: if a moves at speed s, then it covers distance d. if a moves with
// speed s/2, then the distance covered will be d/2. that is the logic used here also. 
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int length=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            length++;
        }
        length=(length/2);
        temp=head;
        while(length){
            temp=temp->next;
            length--;
        }
        return temp;
    }
};