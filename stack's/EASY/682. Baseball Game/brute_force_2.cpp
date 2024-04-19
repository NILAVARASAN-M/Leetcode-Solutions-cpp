#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> vect;
        int sum=0;
        for(string &val: operations){
            if(val=="+"){
                vect.push_back(vect.back()+vect[vect.size()-2]);
                sum+=vect.back();
            }
            else if(val=="D"){
                vect.push_back(2*vect.back());
                sum+=vect.back();
            }
            else if (val=="C"){
                sum-=vect.back();
                vect.pop_back();
            }
            else{
                vect.push_back(stoi(val));
                sum+=vect.back();
            }
        }
        return sum;
    }
};