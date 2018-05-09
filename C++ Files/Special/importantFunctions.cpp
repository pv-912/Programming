#include <bits/stdc++.h>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

int GCD(int A, int B) {
    int m = min(A, B), gcd;
    for(int i = m; i > 0; --i){
        if(A % i == 0 && B % i == 0) {
            gcd = i;
            return gcd;
        }
    }
}
void factorisation( long long int x){
	vector<long long int> b;
	for(long long int i = 2; i<sqrt(x); i++){
		while(x % i  == 0){
			b.push_back(i);
			x = x/i;
		}
	}
	if (x > 2){
       b.push_back(x);
	}

	for(long long int j = 0; j<b.size(); j++){
		cout<<" "<<b[j];
	}
	cout<<endl;
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

void primeFactors(long long int n){
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
	for(long long int j = 0; j<b.size(); j++){
		cout<<" "<<b[j];
	}
}
int divisors(long long n){
    if(n<=1){
        return 0;
    }
    int a = 0;
    for(int i=2; i<=n; i++){
        if(n%i == 0){
            a++;
        }
    }
     return a;   
}
bool checkPrime(long long n){
    if(n<=1){
        return false;
    }

    for(int i=2; i<n; i++){
        if(n%i == 0)
            return false;

        return true;
    }
}

int main(){
	int a = 1;
	int b = 2;

	swap(a,b);
	cout<<a<<" "<<b<<endl;

	cout<<GCD(30,75)<<endl;


}