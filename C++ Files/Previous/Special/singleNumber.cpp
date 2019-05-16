/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example :

Input : [1 2 2 3 1]
Output : 3
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int singleNumber(vector<int> &a) {   
   int result = 0;
    for (int i = 0; i<a.size(); i++)
    {
      result ^=a[i];
      cout<<result;
    }
   return result;
}


int main() {
    vector<int>  a = {4,1,2,2,3,1,3,6,4};
    cout<<singleNumber(a);

    return 0;
}