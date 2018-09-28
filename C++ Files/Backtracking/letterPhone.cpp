#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


void solve(string A, vector<string> a, vector<string> &res, int len, int index, int &templen, int &i, string& temp){
    if(templen==len){
        res.push_back(temp);
        return; 
    }
    string p = "";
    p = accumulate(a[(A[i]-int('0'))].begin(), a[(A[i]-int('0'))].end(),p);
    // cout<<p<<" ";
    
    // cout<<temp<<" ";
    for(int j = index; j<p.length(); j++){
        string temp1 = temp;
        temp += p[index];
        templen++;
        i++;
        solve(A,a, res, len, j, templen,i,temp);
        temp = temp1;
        i--;
        templen--;
    }
    return;
    
}

vector<string> letterCombinations(string A) {
    vector<string> a = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    int len = A.length();
    int index = 0, templen = 0,i=0;
    vector<string> res;
    string temp = "";
    solve(A, a, res, len, index, templen, i, temp);
    return res;
}


int main(){
    string s = "234";
    
    vector<string> h =letterCombinations(s);
    for(int i=0; i<h.size();i++){
        cout<<h[i]<<" ";
    } 
}