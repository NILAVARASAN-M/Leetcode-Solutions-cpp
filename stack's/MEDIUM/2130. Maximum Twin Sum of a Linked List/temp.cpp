// best reversal method for reversing linked-list.

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

int count=0;

ListNode* reverseList(ListNode* cur, ListNode* prev = nullptr) {
    while (cur != nullptr) {
        swap(cur->next, prev);
        swap(prev != nullptr ? prev->next : prev, cur);
        ::count++;
    }
    return prev;
}

int main(){
    ListNode *ls1=new ListNode(1);
    ListNode *ls2=new ListNode(2, ls1);
    ListNode *ls3=new ListNode(3, ls2);
    ListNode *ls4=new ListNode(4, ls3);
    ListNode *ls5=new ListNode(5, ls4);
    ListNode *ls6=new ListNode(6, ls5);
    ListNode *head=ls6, *temp=ls6;
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl<<"----------"<<endl;
    temp=reverseList(head);
    while(temp){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl<<"----------"<<endl;
    cout<<::count<<endl;
}