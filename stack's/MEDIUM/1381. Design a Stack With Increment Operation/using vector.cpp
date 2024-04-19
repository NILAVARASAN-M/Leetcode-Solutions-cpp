#include<bits/stdc++.h>
using namespace std;

class CustomStack {
public:
    int track=-1;
    vector<int> vect;
    CustomStack(int maxSize) : vect(maxSize, 0){}
    
    void push(int x) {
        if(track+1<vect.size()){
            track++;
            *(vect.begin()+track)=x;
        }
    }
    
    int pop() {
        if(track==-1){
            return -1;
        }
        int val=*(vect.begin()+track);
        return (track--, val);
    }
    
    void increment(int k, int val) {
        int Min_val=min(k, track+1);
        for(auto itr=vect.begin(); itr!=(vect.begin()+Min_val); itr++){
            *itr+=val;
        }
    }
};
