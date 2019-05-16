/*
Given two numbers n and m. Your task is to find first m Geeky GCD numbers which are greater than n.
Geeky GCD numbers : First m numbers greater than n whose GCD with n is equal to smallest prime factor of n.

Input : First line of input contains testcases T. For each testcase T, there will be two positive integers n and m.
Output : For each testcase, output m positive integers.
Constraints :
1 <= T <= 10
1 <= n <= 106 
1 <= m <= 106
Example :
Input :
1
8 3
Output :
10 14 18

Explanation :
First 3 integers greater than n are 10, 14 and 18, whose GCD with n is equal to 2 (which is smallest prime factor of n).
*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int GCD(int A, int B) {
    int m = min(A, B), gcd;
    for(int i = m; i > 0; --i)
        if(A % i == 0 && B % i == 0) {
            gcd = i;
            return gcd;
        }
}

int primeFactors(long long int n){
    vector<long long int> b;
    
    while (n%2 == 0){
        b.push_back(2);
        n = n/2;
    }
 
    for (long long int i = 3; i <= sqrt(n); i = i+2){
        
        while (n%i == 0){
            b.push_back(i);
            n = n/i;
        }
    }

    if (n > 2){
       b.push_back(n);
    }
    return b[0];
}


int main() {
    int T;
    long long m,n;
    cin>>T;
    if(T>10 || T<0){
        return 0;
    }
    while(T--){
        cin>>n>>m;
        if(m>1000000 || m<0 || n<0 || n>1000000){
            return 0;
        }
        int a = primeFactors(n);
        int i = n+1;
        while(m>0){
            if(GCD(n,i) == a){
                cout<<i<<" ";
                m--;
            }
            i++;
        }
    }
}
