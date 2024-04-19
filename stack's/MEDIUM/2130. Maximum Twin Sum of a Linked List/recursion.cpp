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
    int max_val=0;
    ListNode *global_node=nullptr;

    int rec_fn(ListNode *temp){
        if(temp==nullptr){
            return 0;
        }
        int val=rec_fn(temp->next);
        max_val=max(val, temp->val+global_node->val);
        global_node=global_node->next;
        return max_val;
    }

    int pairSum(ListNode* head) {
        global_node=head;
        rec_fn(head);
        return max_val;
    }
};