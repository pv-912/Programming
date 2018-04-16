/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.

*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

vector<int> plusOne(vector<int> &a) {
    string x;
    int size = a.size();
    vector<int> c = a;
    int i = size-2;
    if(c[size-1] == 9){
        c[size-1] = 0;
        while(c[i] == 9){
            c[i] = 0;
            i--;
        }
        if(i<0){
            c.insert(c.begin(),1);
        }else{
            c[i] = c[i] +1;
        }
    }
    else{
        c[size - 1] = c[size-1] +1;
    }

    while(c[0] == 0){
        c.erase(c.begin());
    }
    return c;
}

int main() {
   vector<int> a;
   a = { 9, 9, 9, 9, 9 };
   vector<int> b = plusOne(a);
     for(int i=0;i<b.size();i++){
        cout<<" "<<b[i]<<" ";
     }
   // plusOne(a);
    return 0;
}