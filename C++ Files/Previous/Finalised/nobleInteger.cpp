/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int solve(vector<int> &a){
    int n =(int) a.size();
    int ifPresent = -1;
    
    if(!n){
        return ifPresent;
    }
    sort(a.begin(), a.end());
    int i = 0;
    while( i < n ){
        while(i+1<n && a[i] == a[i+1]){
            i++;
        }
        if(a[i] == (n-i-1)){
            ifPresent = 1;
            break;
        }
        i++;
    }
    return ifPresent;
}

int main() {
    vector<int> a;
    a = {  3,4,5,6,7,8,9,10,11,12};
    cout<<solve(a);
    return 0;
}
