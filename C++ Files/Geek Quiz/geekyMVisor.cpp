/*

Given two numbers n and m. Find if n is Geek-m-visor.

Geek-m-visor : A number is called Geek-m-visor if it has exactly m even divisors for a given n.

Input : First line of input contains testcase T. For each testcase, there will be two positive integers n and m.
Output : For each testcase, output "YES" or "NO" (without quotes).

Constraints :
1 <= T <= 10
1 <= n <= 106
1 <= m <= 106

Example :
Input :
1
24 6
Output :
YES

Explanation :
24 has exactly 6 numbers of even divisors. They are 2, 4, 6, 8, 12, 24.
*/

#include <iostream>
#include <cmath>
using namespace std;

int evenDivisors(long long n){
    if(n<=1){
        return 0;
    }
    int a = 0;
    for(int i=2; i<=n; i++){
        if(n%i == 0 && i%2 == 0){
            // cout<<i<<" ";
            a++;
        }
    }
     return a;   
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
        int x = evenDivisors(n);
        if(x==m){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }
}
