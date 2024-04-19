struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#include<stack>
using namespace std;

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> sta;
        ListNode *temp=head;
        while(temp){
            sta.push(temp->val);
            temp=temp->next;
        }
        int mid=sta.size()/2;
        for(int i=0;i<=mid;i++){
            if(sta.top()!=head->val){
                return false;
            }
            sta.pop();
            head=head->next;
        }
        return true;
    }
};