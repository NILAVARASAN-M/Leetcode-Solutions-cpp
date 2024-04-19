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
        vector<int> vect;
        ListNode *slow=head, *fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        while(head!=slow){
            vect.push_back(head->val);
            head=head->next;
        }
        for(auto itr=vect.rbegin();itr!=vect.rend(); itr++){
            *itr+=slow->val;
            slow=slow->next;
        }
        int max_value=*(max_element(vect.begin(), vect.end()));
        return max_value;
    }
};