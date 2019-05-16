/*
Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]

*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
vector<vector<int> > generate(int a) {
    vector<vector<int> > x;
    vector<int> row;
    row.push_back(1);
    for(int i=0; i<a; i++){
        if(i>0){
            row.push_back(1);
        }
        for(int j=1; j<i; j++){
            if(i>1){
                row.push_back(x[i-1][j] + x[i-1][j-1]);
            }
        }
        if(i>0){
            row.push_back(1);
        }
        x.push_back(row);
        row.clear();
    }
    return x;
}
int main() {
    vector<vector<int> > a = generate(5);
     for(int i=0;i<a.size();i++){
        cout<<"[";
        for(int j=0;j<i+5;j++){
            cout<<" "<<a[i][j]<<" ";
        }
        cout<<"] ";
     }
    return 0;
}
