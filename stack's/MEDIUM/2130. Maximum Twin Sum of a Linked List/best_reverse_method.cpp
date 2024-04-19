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
    ListNode* reverse(ListNode *current, ListNode *prev=nullptr)
    {
        while(current!=nullptr){
            swap(current->next, prev);
            swap((prev!=nullptr)? prev->next: prev, current);
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        int res = 0;
        auto slow = head, fast = head;
        while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
        }
        fast=reverse(slow);
        while(fast){
            res=max(res, fast->val+head->val);
            head=head->next;
            fast=fast->next;
        }
        return res;
    }
};