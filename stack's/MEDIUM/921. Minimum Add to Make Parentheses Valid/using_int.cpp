#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0, check=0;
        for(char &val: s){
            if(val=='('){
                check++;
            }
            else{
                if(check==0) count++;
                else check--;
            }
        }
        return count+check;
    }
};