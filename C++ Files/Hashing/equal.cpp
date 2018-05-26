/*
Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
*/

#include <iostream>
#include<unordered_set>
#include <vector>
#include<map>
#include<algorithm>
#include <climits>
using namespace std;

vector<int> equal(vector<int> &A) {
   vector<int>res, v;
   int n = A.size();
   int sum, resi = INT_MAX, resj = INT_MAX, resk = INT_MAX, resl = INT_MAX;
   map<int,vector<int>> :: iterator it;
   map<int,vector<int>>m;
   for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           sum = A[i]+A[j];
           m[sum].push_back(i);
           m[sum].push_back(j);
       }
   }
   for(it=m.begin();it!=m.end();it++){
       v = it->second;
       if(v.size()>2){
            resk = resl = INT_MAX;
            for(int i = 2; i<v.size(); i = i+2){
                if(v[i]<=resk && v[0]<=resi && v[1]<=resj && v[0] < v[1] && v[i] != v[i+1] && v[0] < v[i]  && v[1] != v[i] && v[1] != v[i+1]){   // A1 < B1, C1 < D1 A1 < C1, B1 != D1, B1 != C1 
                    resk = v[i];
                    if(v[i+1]<resl ){
                        resl = v[i+1];
                        resj = v[1];
                        resi = v[0];
                    }
                    res.clear();
                    res.push_back(resi);
                    res.push_back(resj);
                    res.push_back(resk);
                    res.push_back(resl);
                }
            }
       }
   }
   return res;
}

int main(){
    
    vector<int> v = {0,0,1,0,2,1};
    vector<int> c = equal(v);
    for (int i = 0; i < c.size(); ++i)
    {
        cout<<c[i]<<" ";
    }
}
