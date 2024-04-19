#include<bits/stdc++.h>
using namespace std;

int main(){
    int num1=-1; // num1 which is of type int, which means its range from (-)2^31 to (+)2^31-1
    size_t num2=100; // num2 type is size_t, which means num2 is an unsigned number, and it range is 0 to (+)2^32-1
    cout<<(96<'a');  // 
    cout<<(num1<num2)<<endl; // so the comparsion autmatically convertes, num1 to unsigned since size_t is unsigned,
    // since -1 not possible, so the value given to num1 will be 2^32-1.
    // refer ../extra courses/c++/Possible errors/comparsion_error.cpp --> here explained clearly.
}