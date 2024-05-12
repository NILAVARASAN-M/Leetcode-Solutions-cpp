#include<bits/stdc++.h>
using namespace std;
struct Node{
    int key, val;
    Node *next;
    Node(int num1, int num2): key(num1), val(num2), next(nullptr){}
};

class MyHashMap {
public:
        vector<Node*> vect;
        int N=100;
    MyHashMap() {
        for(int i=0;i<N;i++){
            vect.push_back(nullptr);
        }
    }

    int my_hash_function(int key){
        int val=key*123+key^1+12;
        return (val)%N;
    }
    
    void put(int key, int value) {
        int hash_val=my_hash_function(key);
        Node *head=vect[hash_val];
        while(head){
            if(head->key==key){
                head->val=value;
                return;
            }
            head=head->next;
        }
        Node* temp=new Node(key, value);
        temp->next=vect[hash_val];
        vect[hash_val]=temp;
        return;
    }
    
    int get(int key) {
        int hash_val=my_hash_function(key);
        Node *head=vect[hash_val];
        while(head){
            if(head->key==key){
                return head->val;
            }
            head=head->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash_val=my_hash_function(key);
        Node *head=vect[hash_val];
        if(head && head->key==key) {
            vect[hash_val]=head->next;
            return;
        }

        Node *prev=head;
        while(head){
            if(head->key==key){
                prev->next=head->next;
                return;
            }
            prev=head;
            head=head->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */