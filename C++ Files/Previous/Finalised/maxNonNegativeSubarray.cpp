/*
Find out the maximum sub-array of non negative numbers from an array.
The sub-array should be continuous. That is, a sub-array created by choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:

A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]
NOTE: If there is a tie, then compare with segment's length and return segment which has maximum length
NOTE 2: If there is still a tie, then return the segment with minimum starting index

*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> subArray(vector<int> &a){
    int size =(int) a.size();
    int currentSum = 0,maxSum = 0;
    vector<int> b;
    vector<int> c; 
    int j = 0;
    b.push_back(0);
    while(a[j]>0){
        currentSum = a[j] + currentSum;
        b[0] = b[0] + 1;
        b.push_back(a[j]);
        j++;
    }
    maxSum = currentSum;
    currentSum = 0;
    c.push_back(0);
    for(int i=j+1; i<size; i++){
        if(a[i]>=0){
            currentSum = a[i] + currentSum;
            c[0] = c[0] + 1;
            c.push_back(a[i]);
            if(currentSum > maxSum){
                maxSum = currentSum;
                b = c;
            } 
            else if(currentSum == maxSum){
                if(b.size() < c.size()){
                    b = c;
                } else if(b.size() == c.size()){
                    if(b[0] > c[0]){
                        b = c;
                    }
                }
            }
        }
        else if(a[i]<=0){
                currentSum = 0;
                c.clear();
                c.push_back(0);
        }
    }
    return b;
}

int main() {
    vector<int> a;
    a = { 1, 2, 5, -7, 2, 3 ,10, -1, 5, 3, -5, 8, 7, 4};
    vector<int> ans = subArray(a);
    // cout<<ans.size();
    for (int i=0; i<ans.size();i++)
      {
          cout<<" "<<ans[i];
      }
    return 0;
}

