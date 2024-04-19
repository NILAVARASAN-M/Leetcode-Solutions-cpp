#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int i=0;
        while(!students.empty() && i<students.size()){
            if(students.front()==sandwiches.front()){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                i=0;
            }
            else{
                int val=*(students.begin());
                students.erase(students.begin());
                students.push_back(val);
                i++;
            }
        }
        return students.size();
    }
};

