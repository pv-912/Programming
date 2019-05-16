/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
For example:
Given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
For this problem, return the maximum sum.
*/

#include <iostream>
#include <vector>
using namespace std;

int maxSubArray( vector<int> &a) {
   int size = a.size();
   int maxTill= 0, maxRecent = 0;
    for (int i = 0; i < size; i++){
       maxRecent = maxRecent + a[i];
       
       if(maxRecent>maxTill){
            maxTill = maxRecent;
       }
       if(maxRecent<0){
        maxRecent =0;
       }
    }
    int j=0,temp = a[0];
    while(a[j]<=0 && j<size){
        if(temp<a[j]){
            temp = a[j];
        }
        j++;
    }
    if(j== size){
        maxTill = temp;
    }
    return maxTill;
}

int main() {
    vector<int> a;
    a = { -163,-20};
    cout<< maxSubArray(a)<<endl;
    return 0;
}