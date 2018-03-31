/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

bool larger(int x, int y){
    string a = to_string(x);
    string b = to_string(y);
    string ab = a + b;
    string ba = b+a;
    if(ba<ab){
        return true; 
    }
    return false;
}

string solve(const vector<int> &a){
    vector<int> b = a;

    sort(b.begin(), b.end(), larger);
    string x;
    for(int i=0; i<b.size(); i++){
        x = x + to_string(b[i]);
    }

    if(x=="0"){
        return "0";
    }
    return x;
}

int main() {
     vector<int> a;
    a = {  472, 663, 964, 722, 485, 852, 635, 4, 368, 676, 319, 412};
    cout<<solve(a);
    return 0;
}
