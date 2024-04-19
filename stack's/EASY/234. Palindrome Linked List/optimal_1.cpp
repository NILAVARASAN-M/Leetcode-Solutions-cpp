struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head, *slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *prev=nullptr, *current=nullptr, *next=slow;
        while(next){
            prev=current;
            current=next;
            next=next->next;
            current->next=prev;
        }

        while(current){
            if(current->val!=head->val){
                return false;
            }
            current=current->next;
            head=head->next;
        }
        return true;
    }
};