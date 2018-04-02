/*
Print concentric rectangular pattern in a 2d matrix. 
Let us show you some examples to clarify what we mean.
Example 1:
Input: A = 4.
Output:

4 4 4 4 4 4 4 
4 3 3 3 3 3 4 
4 3 2 2 2 3 4 
4 3 2 1 2 3 4 
4 3 2 2 2 3 4 
4 3 3 3 3 3 4 
4 4 4 4 4 4 4 
The outermost rectangle is formed by A, then the next outermost is formed by A-1 and so on.
You will be given A as an argument to the function you need to implement, and you need to return a 2D array.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

vector<vector<int> > spiralOrder( int a) {
   int size = 2*a-1;
    vector<vector<int> >    v(size, vector<int>(size));;
    int b,r,toPush,q;
     toPush = a;
    b = r =size, q = size*size;
    int l = 0,t = 0, x= 0,j=0;
    vector<int> row;
    while(j<q && toPush>0){
        if(x == 0){
            for(int i=l;i<r && j<q ;i++){
                v[t][i] = toPush;
                j++;
                if(i == r-1){
                    t = t + 1;
                }
            }
            x = 1;
        }
        else if(x == 1){
            for(int i=t;i<b && j<q;i++){
               v[i][r-1] = toPush;
                j++;
                if(i == b-1){
                    r = r-1;
                }
            }
            x = 2;
        }
        else if(x == 2){
            for(int i=r;i>l && j<q;i--){
                v[b-1][i-1] = toPush;
                j++;
                if(i - 1 == l ){
                    b = b-1;
                }
            }
            x = 3;
        }
        else if(x == 3){
            for(int i=b;i>t && j<q;i--){
                v[i-1][l] = toPush;
                j++;
                if(i == t + 1 ){
                    l = l + 1;
                }
            }
            x = 0;
            toPush--;
        }
    }
    return v;
}

int main() {
    vector<vector<int> > a ;
    int v = 8;
    a = spiralOrder(v);
    for(int i=0;i<a.size();i++){
        cout<<"[";
        for(int j=0;j<a[i].size();j++){
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<"] ";
     }
    return 0;
}