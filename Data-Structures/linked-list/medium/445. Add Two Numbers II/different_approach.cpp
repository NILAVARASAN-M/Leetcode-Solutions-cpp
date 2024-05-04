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


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
int length(ListNode* node){
    if(node==nullptr){
        return 0;
    }
    return length(node->next)+1;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1=length(l1), len2=length(l2);
        ListNode* res=nullptr;
        while(len1!=0 || len2!=0){
            int sum=0;
            if(len1>=len2) sum+=l1->val, l1=l1->next ,len1--;
            if(len2>len1) sum+=l2->val, l2=l2->next, len2--;
            res=addNode(sum, res);
        }
        int carry=0;
        ListNode* newNode=nullptr;
        while(res){
            int temp=res->val+carry;
            newNode=addNode(temp%10, newNode);
            carry=temp/10;
            ListNode *delNode=res;
            res=res->next;
            delete delNode;
        }
        if(carry==1) newNode=addNode(carry, newNode);
        return newNode;
    }

    ListNode* addNode(int val, ListNode* node2){
        ListNode* node=new ListNode(val);
        node->next=node2;
        return node;
    }
};