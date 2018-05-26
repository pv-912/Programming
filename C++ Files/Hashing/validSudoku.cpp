#include <bits/stdc++.h>

using namespace std;

int isValidSudoku( vector<string> &arr) {
    int size = arr.size(), tempSize, j;
    int a[size][size];
    string s;
    for(int i = 0;i<size;i++){
        s = accumulate(begin(arr[i]), end(arr[i]), s);
        for(int j = 0;j<size;j++){
            if(s[j]!='.'){
                a[i][j] = s[j]-48;
            }
            else{
                a[i][j] = -2;
            }
        }
        s="";
    }
    unordered_set<int> m,n;
    for(int i = 0;i<size;i++){
        for(int k = 0;k<size;k++){
            //row
            if(  a[i][k]>0 &&  m.find(a[i][k])!=m.end()){
                return 0;
            }
            else{
                m.insert(a[i][k]);
            }
            //column
            if( a[k][i]>0 && n.find(a[k][i])!=n.end()){
                return 0;
            }
            else{
                n.insert(a[k][i]);
            }
        }
        m.clear();
        n.clear();
    }
    // squares
    int x = 0, y = 0;
    while(x<size){
        while(y<size){
            for(int i = x;i<x+3;i++){
                for(int k = y;k<y+3;k++){
                    if(a[i][k]>0 &&   m.find(a[i][k])!=m.end()){
                        return 0;
                    }
                    else{
                        m.insert(a[i][k]);
                    }
                }
            }
            m.clear();
            y += 3;
        }
        x += 3;
    }
    return 1;
}

int main(){
    vector<string> a = {"53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"};

    cout<<isValidSudoku(a);
}