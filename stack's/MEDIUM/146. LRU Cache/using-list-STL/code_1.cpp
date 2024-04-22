#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    list<pair<int, int>> lst;
    unordered_map<int, list<pair<int, int>>::iterator> umap;
    int cap;
    LRUCache(int capacity): cap(capacity) {}
    
    int get(int key) {
        if(umap.count(key)==0) return -1;
        auto node=umap[key];
        int val=node->second;
        lst.splice(lst.begin(), lst, node);
        return val;
    }
    
    void put(int key, int value) {
        if(umap.count(key)==1){
            auto node=umap[key];
            lst.splice(lst.begin(), lst, node);
            node->second=value;
            return;
        }
        else if(umap.size()==cap){
            int del_key=lst.back().first;
            umap.erase(del_key);
            lst.pop_back();
        }
        lst.push_front(make_pair(key, value));
        umap[key]=lst.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */