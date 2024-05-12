#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node *next;
    Node(int num): key(num), next(nullptr){}
};


class MyHashSet {
public:
    int N=100;
    vector<Node*> vect;
    MyHashSet() {
        for(int i=0;i<N;i++){
            vect.push_back(nullptr);
        }
    }
    
    int my_hash_function(int key){
        int val=key*123+key^1+12;
        return (val)%N;
    }
    
    void add(int key) {
        int hash_val=my_hash_function(key);
        Node *head=vect[hash_val];
        while(head){
            if(head->key==key){
                return;
            }
            head=head->next;
        }
        Node* temp=new Node(key);
        temp->next=vect[hash_val];
        vect[hash_val]=temp;
        return;
    }
    
    bool contains(int key) {
        int hash_val=my_hash_function(key);
        Node *head=vect[hash_val];
        while(head){
            if(head->key==key){
                return true;
            }
            head=head->next;
        }
        return false;
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
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */