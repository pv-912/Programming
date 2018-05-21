/*
Given two numbers n and m. Your task is to find if n is Geeky-m-Power-of-Prime.
Geeky-m-Power-of-Prime : A number is called Geeky-m-Power-of-Prime if it is m-th power of a prime number.

Input : First line of input contains testcases T. For each testcase, there will be two positive integers n and m.
Output : For each testcase, output "YES" or "NO" (without quotes).
Constraints :
1 <= T <= 10
1 <= n <= 106
1 <= m <= 106
Example :
Input :
1
16 4
Output :
YES

Explanation :
16 is m-th (4th) power of 2, where 2 is prime.
*/

#include <iostream>
#include <cmath>
using namespace std;


void sieveMethod( long long n) {
    bool isPrime[n+1];
    bool res = 0;
    for(long long i = 0; i <= n;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(long long i = 2; i * i <= n; ++i) {
         if(isPrime[i] == true) {
             for(long long j = i * i; j <= n ;j += i)
                 isPrime[j] = false;
        }
    }

    for (long long i = 0; i < n; ++i)
    {
        if(isPrime[i]==true){
                if(i == n-1){
                res = 1;
            }
        }
    }

    if(res){
        cout<<"YES";
    }
    else{
        cout<<"NO";
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
        float x = pow(n,1.0/(m));
        n = (int)x;
        n++;
        sieveMethod(n);
    }
}
