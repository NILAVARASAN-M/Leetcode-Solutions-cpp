#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> vect;
        int i=0, j=1;
        while(i<target.size() && n>=j){
            vect.push_back("Push");
            if(target[i]!=j){
                vect.push_back("Pop");
            }
            else{
                i++;
            }
            j++;
        }
        return vect;
    }
};