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
#include <bits/stdc++.h>
using namespace std;

int main()
{  
   int t=0;
   long long int m=0,n=0;
   cin>>t;
   if(t>10){
      return 0;
   }
   while(t>0){
      cin>>m>>n;
      if(( m<1 || n<1 || m> 1000000000 || n>1000000000 || (n-m)>100000 || (n-m)<0)){
         return 0;
      }
      long long int SIZE = n;
      bool sieve [SIZE] = {0};
      for (long long int i = 2; i<= SIZE; i++){ 
         for(long long int j = i*i; j <=SIZE; j+=i ){
            sieve[j] = true;
         }
      }
      if(m==1){
         m=2;
      }

      for(long long int i = m; i<=n;i++){  
         if(sieve[i]==0){
            cout<<i<<endl;
         }
      }
      cout<<endl;
      t--;
   }
   return 0;
 }