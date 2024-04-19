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
    ListNode* reverse(ListNode *temp){
        if(temp->next==nullptr){
            return temp;
        }
        ListNode *for_return=reverse(temp->next);
        temp->next->next=temp;
        temp->next=nullptr;
        return for_return;
    }

    int pairSum(ListNode* head) {
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        fast=reverse(slow);
        int max_val=numeric_limits<int>::min();
        while(fast){
            int val=fast->val+head->val;
            max_val=max(val, max_val);
            fast=fast->next;
            head=head->next;
        }
        return max_val;
    }
};