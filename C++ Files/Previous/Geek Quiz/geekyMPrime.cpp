/*
Given two numbers n and m. Your task is to find if the given number n is Geeky-m-prime.
Geeky-m-Prime : A number is called Geeky-m-prime, if it is m distance ahead of a prime in natural number series.

Input : First line of input contains testcase T. For each testcase T, there will be two positive integers n and m.
Output : For each testcase, output "YES" or "NO" (without quotes).

Constraints :
1 <= T <= 10
3 <= n <= 106
0 <= m <= 106

Example :
Input :
1
8 3
Output :
YES

Explanation :

In the above example, n = 8 and m = 3.  8 is a number which is 3 ahead of prime number 5.  Therefore 8 is Geeky-3-Prime.
*/
#include <iostream>
#include <cmath>
using namespace std;


bool check(long long n){
    if(n<=1){
        return false;
    }

    for(int i=2; i<n; i++){
        if(n%i == 0)
            return false;

        return true;
    }
    
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
        long long a = n - m;
        bool res = check(a);
        if(res){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
}
