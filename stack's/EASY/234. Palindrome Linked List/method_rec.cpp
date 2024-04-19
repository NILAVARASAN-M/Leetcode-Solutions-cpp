struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* temp=nullptr;
    bool reverse(ListNode* head)
    {
        if(head==nullptr){
            return true;
        }
        bool val=reverse(head->next) && head->val==temp->val;
        temp=temp->next;
        return val;
    }
    bool isPalindrome(ListNode* head) {
        temp=head;
        return reverse(head);
    }
};