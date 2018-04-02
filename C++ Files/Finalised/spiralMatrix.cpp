/*
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.
Example:
Given the following matrix:
[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

vector<int> spiralOrder( vector<vector<int> > &a) {
    vector<int> v;
    int b = a.size();
    int q = a.size()*a[0].size();
    int r = a[0].size();
    int l = 0,t = 0, x= 0,j=0;
    while(j<q){
        if(x == 0){
            for(int i=l;i<r && j<q ;i++){
                v.push_back(a[t][i]);
                j++;
                if(i == r-1){
                    t = t + 1;
                }
            }
            x = 1;
        }
        else if(x == 1){
            for(int i=t;i<b && j<q;i++){
                v.push_back(a[i][r-1]);
                j++;
                if(i == b-1){
                    r = r-1;
                }
            }
            x = 2;
        }
        else if(x == 2){
            for(int i=r;i>l && j<q;i--){
                v.push_back(a[b-1][i-1]);
                j++;
                if(i - 1 == l ){
                    b = b-1;
                }
            }
            x = 3;
        }
        else if(x == 3){
            for(int i=b;i>t && j<q;i--){
                v.push_back(a[i-1][l]);
                j++;
                if(i == t + 1 ){
                    l = l + 1;
                }
            }
            x = 0;
        }
    }
    return v;
}

int main() {
    vector<vector<int> > a = {{1, 2},{3, 4},{5, 6}};
    vector<int> v;
    v = spiralOrder(a);
    for(int i=0;i<v.size();i++){
        cout<<" "<<v[i]<<" ";
    }
    return 0;
}
