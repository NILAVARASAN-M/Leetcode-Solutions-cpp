#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int capacity, track;
    unordered_map<int, int> umap;
    deque<int> deq;
    LRUCache(int capacity): capacity(capacity), track(0) {}
    
    int get(int key) {
        if(umap.count(key)==0){
            return -1;
        }
        auto itr=find(deq.begin(), deq.end(), key);
        deq.erase(itr);
        deq.push_back(key);
        return umap[key];
    }
    
    void put(int key, int values) {
        if(umap.count(key)==1){
            auto itr=find(deq.begin(), deq.end(), key);
            deq.erase(itr);
            deq.push_back(key);
            umap[key]=values;
        }
        else if(track<capacity){
            deq.push_back(key);
            umap[key]=values;
            track++;
        }
        else{
            int val=deq.front();
            deq.pop_front();
            umap.erase(val);
            deq.push_back(key);
            umap[key]=values;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */