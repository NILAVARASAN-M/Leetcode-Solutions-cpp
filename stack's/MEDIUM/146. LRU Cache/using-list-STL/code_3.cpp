#include<bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    typedef list<int> TL;
    typedef pair<int, TL::iterator> TP;
    typedef unordered_map<int, TP> TU;

    int cap;
    TL lst;
    TU umap;

    void touch(TU::iterator itr){
        int key=itr->first;
        auto node=itr->second.second;
        lst.erase(node);
        lst.push_front(key);
        itr->second.second=lst.begin();
    }

public:
    LRUCache(int capacity): cap(capacity) {}
    
    int get(int key) {
        auto it = umap.find(key);
        if (it == umap.end()) return -1;
        touch(it);
        return it->second.first;
    }
    
    void put(int key, int value) {
        auto itr=umap.find(key);
        if(itr!=umap.end()){
            touch(itr);
        }
        else{
            if(umap.size()==cap){
                umap.erase(lst.back());
                lst.pop_back();
            }
            lst.push_front(key);
        }
        umap[key]=make_pair(value, lst.begin());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */