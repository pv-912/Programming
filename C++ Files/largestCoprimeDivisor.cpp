/*
You are given two positive numbers A and B. You need to find the maximum valued integer X such that:

X divides A i.e. A % X = 0
X and B are co-prime i.e. gcd(X, B) = 1
For example,

A = 30
B = 12
We return
X = 5
*/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){              //  using modulus
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int cpFact(int a, int b) {
    int x = gcd(a,b);
    a = a/x;
    if(gcd(b,a) == 1){
        return a;
    }
    else{
        cpFact(a,b);
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    cout<<cpFact(a,b);
}
