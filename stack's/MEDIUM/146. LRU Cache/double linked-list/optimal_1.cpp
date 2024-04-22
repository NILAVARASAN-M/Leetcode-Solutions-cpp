#include<bits/stdc++.h>
using namespace std;

struct DoubleNode{
    int key, val;
    DoubleNode *prev, *next;
    DoubleNode(int num1, int num2): key(num1), val(num2), prev(nullptr), next(nullptr){}
};
class LRUCache {
public:
    DoubleNode *head, *tail;
    int cap;
    unordered_map<int, DoubleNode*> umap;

    LRUCache(int capacity) {
    head=new DoubleNode(-1, -1);
    tail=new DoubleNode(-1, -1);
    cap=capacity;
    head->next=tail;
    tail->prev=head;
    }
    void deleteNode(DoubleNode *node){
        DoubleNode *left=node->prev;
        DoubleNode *right=node->next;
        right->prev=left;
        left->next=right;
    }
    void addNode(DoubleNode *node){
        DoubleNode *right=head->next;
        node->next=right;
        node->prev=head;
        head->next=node;
        right->prev=node;
    }
    int get(int key) {
        if(umap.count(key)==0) return -1;
        DoubleNode *node=umap[key];
        int val=node->val;
        deleteNode(node);
        addNode(node);
        umap[key]=head->next;
        return val;
    }
    
    void put(int key, int value) {
        if(umap.count(key)==1){
            DoubleNode *node=umap[key];
            deleteNode(node);
            addNode(node);
            umap[key]=head->next;
            head->next->val=value;
            return;
        }
        else if(cap==umap.size()){
            DoubleNode *node=tail->prev;
            deleteNode(node);
            umap.erase(node->key);
            DoubleNode *newNode=new DoubleNode(key, value);
            addNode(newNode);
            umap[key]=newNode;
            return;
        }
        else{
            DoubleNode *newNode=new DoubleNode(key, value);
            addNode(newNode);
            umap[key]=newNode;
        }
    }
};

//  Your LRUCache object will be instantiated and called as such:
  int main(){
  LRUCache* obj = new LRUCache(2);
  obj->put(1,1);
  obj->put(2,2);
  cout<<obj->get(1)<<endl;
  obj->put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
cout<<obj->get(2)<<endl;    // returns -1 (not found)
obj->put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
cout<<obj->get(3)<<endl;    // return -1 (not found)
cout<<obj->get(3)<<endl;    // return 3
cout<<obj->get(4)<<endl;    // return 4
}