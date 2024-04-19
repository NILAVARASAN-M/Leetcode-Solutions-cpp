#include<bits/stdc++.h>
using namespace std;
 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *slow, *fast, *current, *prev;
        slow=fast=head;
        current=prev=nullptr;
        while(fast && fast->next){
            fast=fast->next->next;
            prev=current;
            current=slow;
            slow=slow->next;
            current->next=prev;
        }
        int max_num=0;
        while(slow){
            max_num=max(max_num, slow->val+current->val);
            slow=slow->next;
            current=current->next;
        }
        return max_num;
    }
};