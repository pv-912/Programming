

/*
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!
Input
The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.
Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.
Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5

*/

#include<iostream>
#include<vector>
#include <cmath>
using namespace std;

void sieveMethod(long long int m,long long int N) {
    vector<long long int> a;

    vector<bool> isPrime;
    int sqrtM =  sqrt(m) ;

    for(long long int i = 0; i <= sqrtM; ++i) {
        isPrime.push_back(true);
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(long long int i = 2; i * i <= sqrtM; ++i) {
         if(isPrime[i] == true) {
             for(long long int j = i * i; j <= sqrtM ;j += i)
                 isPrime[j] = false;
        }
    }


    bool x = 1;
    for (long long int i = m; i < N; ++i){
        if(isPrime[i]==true){
            cout<<i<<endl;
        }
    }
}

int main()
{  
   int t=0;
   long long int m,n;
   cin>>t;
   if(t>10){
      return 0;
   }
   while(t--){
      cin>>m>>n;
      if(( m<1 || n<1 || m> 1000000000 || n>1000000000 || (n-m)>100000 || (n-m)<0)){
         return 0;
      }
      sieveMethod( m, n+1);
   }
   return 0;
 }