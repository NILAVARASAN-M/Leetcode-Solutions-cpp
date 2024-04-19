#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> vect;
        for(string &val: operations){
            if(val=="+") vect.push_back(vect.back()+vect[vect.size()-2]);
            else if(val=="D") vect.push_back(2*vect.back());
            else if(val=="C") vect.pop_back();  
            else vect.push_back(stoi(val));
        }
        return accumulate(vect.begin(), vect.end(), 0);
    }
};