#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for (i = 0; i < n; ++i)
#define REP(i,k,n) for (i = k; i <= n; ++i)
#define REPR(i,k,n) for (i = k; i >= n; --i)

void ifOdd(int x)
{
   (x & 1)? printf("Odd"): printf("Even");
}

// itertion should be as
void hello(){

    vector<int> vec = {0, 1, 2, 3, 4};
    for (const auto &value : vec)
        cout << value << ' ';
 
    cout << '\n';
    int array[]= {1, 2, 3, 4, 5};
    for (const auto &value: array)
        cout << value << " ";
}

void swapWithOutUsingExtraVariale(int &x , int &y){
      x = x + y;  // x now becomes 15
      y = x - y;  // y becomes 10
      x = x - y;  // x becomes 5

      //  less efficient memory overflow
      x = x * y;  // x now becomes 50
      y = x / y;  // y becomes 10
      x = x / y;  // x becomes 5
}

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

void swap(int &x, int &y){
        if (x == y) // Check if the two addresses are same
      return;
     x = x ^ y;  // x now becomes 15 (1111)
      y = x ^ y;  // y becomes 10 (1010)
      x = x ^ y;  // x becomes 5 (0101)
 
}

void sortingAnArrayInOnOfGivenNaturalNumber(vector<int> &a) {
    vector<int> temp = a;
    for(int i = 0; i<a.size();i++){
        a[temp[i]] = temp[i];
    }
}

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int gcdExtended(int a, int b, int *x, int *y)  // Euclidean extended method used for RSA public key encryption
{
    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    // Update x and y using results of recursive call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}
int randomWithInRange(int min, int max) //range : [min, max)
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
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
vector<int> divisors(long long n){
    vector<int> x;
    if(n<=1){
        return 0;
    }
    int a = 0;
    for(int i=2; i<=n; i++){
        if(n%i == 0){
            x.push_back(i);
        }
    }
     return x;   
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
    std::ios_base::sync_with_stdio(false);   
        // add this line to get fast i.o o.p  It toggles on or off the synchronization of all the C++ standard streams with their 
        // corresponding standard C streams if it is called before the program performs its first input or output operation. Adding ios_
        // base::sync_with_stdio (false); (which is true
        // by default) before any I/O operation avoids this synchronization. It is a static member of function of std::ios_base.

    cin.tie(NULL);
    // tie() is a method which simply guarantees the flushing of std::cout before std::cin accepts an input. This is 
    // useful for interactive console programs which require the console to be
    /// updated constantly but also slows down the program for large I/O. The NULL part just returns a NULL pointer.
	int a = 1;
	int b = 2;

	swap(a,b);
	cout<<a<<" "<<b<<endl;

	cout<<GCD(30,75)<<endl;


}