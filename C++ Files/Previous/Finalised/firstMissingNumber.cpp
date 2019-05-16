/*
Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int> &a) {
    int size = a.size();
    int missingNumber = 1;
    sort(a.begin(),a.end());
    int x = -1,i=0;
    for(i; i<size; i++){
        if(a[i]<1){
            x = i;
        }
        else{
            if(a[i] == i-x){
                continue;
            }
            else{
                missingNumber = i-x;
                break;
            }
        }
    }
    if(missingNumber == 1 && a[i-1] > 0){
        missingNumber = a[i-1]+1;
    }
    return missingNumber;
}


int main() {
    vector<int> a;
    a = {1};
    cout<< firstMissingPositive(a)<<endl;
    return 0;
}