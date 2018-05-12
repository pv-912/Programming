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
void sieveMethod(long long int N) {
    vector<long long int> a;
    vector<bool> isPrime;
    for(long long int i = 0; i <= N;++i) {
        isPrime.push_back(true);
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(long long int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             for(long long int j = i * i; j <= N ;j += i)
                 isPrime[j] = false;
        }
    }
    bool x = 1;
    for (long long int i = 0; i < N; ++i){
        if(isPrime[i]==true){
            cout<<i<<" ";
        }
    }
}
int main() {
	sieveMethod(167774);
	// cout<<GCD(30,75);
}