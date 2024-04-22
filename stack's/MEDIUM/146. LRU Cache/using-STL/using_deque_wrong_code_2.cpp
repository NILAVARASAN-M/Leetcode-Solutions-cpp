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
        if(key==1){
            cout<<"here: "<<itr->first<<","<<itr->second<<','<<key<<endl;
        }
        deq.erase(itr);
        deq.push_front(make_pair(key, value));
        umap[key]=deq.begin();
        display();
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
        display();
    }
    void display(){
        for(auto itr=deq.begin();itr!=deq.end(); itr++){
            cout<<'('<<itr->first<<","<<itr->second<<')'<<"     ";
        }
        cout<<endl;
    }
};

//  Your LRUCache object will be instantiated and called as such:
  int main(){
    LRUCache* obj = new LRUCache(10);
    obj->put(7,28);
    obj->put(7,1);
    obj->put(8,15);
    cout<<obj->get(6)<<endl;
    obj->put(10,27);
    obj->put(8,10);
    cout<<obj->get(8)<<endl;
    obj->put(6,29);
    obj->put(1,9); 
    cout<<obj->get(6)<<endl;
    cout<<obj->get(1)<<endl;
    obj->put(10, 7); 
    cout<<obj->get(1)<<endl; //p

    return 0;
}