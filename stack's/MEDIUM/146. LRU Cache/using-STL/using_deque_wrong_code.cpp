#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    deque<pair<int, int>> deq;
    unordered_map<int, deque<pair<int, int>>::iterator> umap;
    int cap;
    LRUCache(int capacity): cap(capacity) {}
    
    int get(int key) {
        if(umap.count(key)==0) return -1;
        auto itr=umap[key];
        int value=itr->second;
        deq.erase(itr);
        deq.push_front(make_pair(key, value));
        umap[key]=deq.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(umap.count(key)==1){
            auto itr=umap[key];
            deq.erase(itr);
            deq.push_front(make_pair(key, value));
            umap[key]=deq.begin();
        }
        else if(cap==umap.size()){
            int o_key=deq.back().first;
            umap.erase(o_key);
            deq.pop_back();
            deq.push_front(make_pair(key, value));
            umap[key]=deq.begin();
        }
        else{
            deq.push_front(make_pair(key, value));
            umap[key]=deq.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */