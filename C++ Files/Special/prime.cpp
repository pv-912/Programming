#include <iostream>
#include <cmath>
using namespace std;

int GCD(int A, int B) {
    int m = min(A, B), gcd;
    for(int i = m; i > 0; --i)
        if(A % i == 0 && B % i == 0) {
            gcd = i;
            return gcd;
        }
}
void sieveMethod(long long N) {
    bool isPrime[N+1];
    for(long long i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(long long i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             for(long long j = i * i; j <= N ;j += i)
                 isPrime[j] = false;
        }
    }

    for (long long i = 0; i < N; ++i)
    {
    	if(isPrime[i]==true){
    		cout<<i<<" ";
    	}
    }
}

int main() {
	sieveMethod(5000000);
	cout<<GCD(30,75);
}