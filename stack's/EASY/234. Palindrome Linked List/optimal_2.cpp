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
        ListNode* return_node=reverse(temp->next);
        temp->next->next=temp;
        temp->next=nullptr;
        return return_node;
    }
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head, *slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *current=reverse(slow);
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