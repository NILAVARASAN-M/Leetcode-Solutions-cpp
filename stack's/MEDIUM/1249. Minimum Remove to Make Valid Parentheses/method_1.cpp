#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> index1, index2;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                index1.push(i);
            }
            else if(s[i]==')'){
                if(index1.empty()){
                    index2.push(i);
                }
                else{
                    index1.pop();
                }
            }
        }

        string temp="";
        for(int i=(int)s.size()-1;i>=0;i--){
            if(!index1.empty() && index1.top()==i){
                index1.pop();
            }
            else if(!index2.empty() && index2.top()==i){
                index2.pop();
            }
            else{
                temp=s[i]+temp;
            }
        }
        return temp;
    }
};