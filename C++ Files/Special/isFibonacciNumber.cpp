#include <iostream>
#include <vector>
using namespace std;

string isFibo(long long n){
    string s = "IsNotFibo";
    vector<int> a;
    a.push_back(0);
    a.push_back(1);
    int i =2;
    while(a[i-1]<n){
        a.push_back(a[i-1] + a[i - 2]);
        i++;
    }
    if(a[i-1] == n){
        s = "IsFibo";
    }
    return s;
}

int main() {
    int T;
    long long n;
    cin>>T;
    if(T>=100000 || T<0){
        return 0;
    }
    while(T--){
        cin>>n;
        if( n< 0|| n>=10000000000){
            return 0;
        }
        string a = isFibo(n);
        cout<<a;
    }
}