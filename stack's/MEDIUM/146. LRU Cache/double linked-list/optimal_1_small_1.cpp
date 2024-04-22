#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key, val;
    Node *prev, *next;
    Node(int num1, int num2): key(num1), val(num2), prev(nullptr), next(nullptr){}
};

class LRUCache {
public:
    Node *head, *tail;
    unordered_map<int, Node*> umap;
    int cap;
    LRUCache(int capacity) {
        head=new Node(-1, -1);
        tail=new Node(-1, -1);
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }
    void deleteNode(Node *node){
        Node *left=node->prev;
        Node *right=node->next;
        left->next=right;
        right->prev=left;
    }

    void addNode(Node *node){
        Node *right=head->next;
        head->next=node;
        right->prev=node;
        node->prev=head;
        node->next=right;
    }

    int get(int key) {
        if(umap.count(key)==0) return -1;
        Node *temp=umap[key];
        int value=temp->val;
        deleteNode(temp);
        addNode(temp);
        return value;
    }
    
    void put(int key, int value) {
        if(umap.count(key)==1){
            Node *temp=umap[key];
            deleteNode(temp);
            addNode(temp);
            head->next->val=value;
            return;
        }
        else if(cap==umap.size()){
            Node *temp=tail->prev;
            umap.erase(temp->key);
            deleteNode(temp);
        }
        addNode(new Node(key, value));
        umap[key]=head->next;
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */