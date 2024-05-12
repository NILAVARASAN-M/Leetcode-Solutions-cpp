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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::vector<ListNode*> vect;
        while(headA || headB){
            if(headA){
            auto itr=std::find(vect.begin(), vect.end(), headA);
            if(itr==vect.end()){
                vect.push_back(headA);
            }
            else{
                return headA;
            }
            headA=headA->next;
        }
            if(headB){
            auto itr=std::find(vect.begin(), vect.end(), headB);
            if(itr==vect.end()){
                vect.push_back(headB);
            }
            else{
                return headB;
            }
            headB=headB->next;
        }
        }
        return NULL;
    }
};