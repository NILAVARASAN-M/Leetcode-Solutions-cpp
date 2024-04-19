#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minLength(string s) {
        auto sub1=s.find("AB");
        auto sub2=s.find("CD");
        while(sub1!=string::npos || sub2!=string::npos){
            if(sub1!=string::npos){
                s.replace(sub1, 2, "");
            }
            else{
                s.replace(sub2, 2, "");
            }
            sub1=s.find("AB");
            sub2=s.find("CD");
        }
        return s.size();
    }
};

int main(){
    Solution obj;
    cout<<obj.minLength("ABFCACDB");
    return 0;
}