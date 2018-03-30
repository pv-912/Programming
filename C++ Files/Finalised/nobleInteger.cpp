/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p
If such an integer is found return 1 else return -1.

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void solve(vector<int> &a){
    int size =(int) a.size();
    vector<int> b;
    int ifPresent = -1;
    int count = 0;
    int i=0,j=0;
    while(ifPresent == -1 && i<size ){
        while(ifPresent == -1 && j<size && a[i] < (size - j - 1) ){
            if(a[j]>a[i]){
                count++;
            }
            j++;
        }
        if(count == a[i]){
            ifPresent = 1;
        }
        cout<<i<<" ";
        i++;
        count = 0; j=0;
    }
    
    cout<< ifPresent;
}

int main() {
    vector<int> a;
    a = {  -2, -7, 1, -2, -1, 6, -6, -7, -7, 3, 8, -4, -10, -6, 8, -2, -2, -1, 7};
    solve(a);
    return 0;
}
