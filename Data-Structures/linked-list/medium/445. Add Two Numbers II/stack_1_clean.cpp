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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> sta1, sta2;
        while(l1)  sta1.push(l1->val), l1=l1->next;
        while(l2)  sta2.push(l2->val), l2=l2->next;
        ListNode *current=nullptr;
        int sum=0;
        while(!sta1.empty() || !sta2.empty() || sum){
            if(!sta1.empty()) sum+=sta1.top(), sta1.pop();
            if(!sta2.empty()) sum+=sta2.top(), sta2.pop();
            ListNode *temp=new ListNode(sum%10);
            sum=sum/10;
            temp->next=current;
            current=temp;
        }
        return current;
    }
};