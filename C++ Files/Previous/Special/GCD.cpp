#include <bits/stdc++.h>
using namespace std;


int GCD(int A, int B) {             // iterative method
    int m = min(A, B), gcd;
    for(int i = m; i > 0; --i){
        if(A % i == 0 && B % i == 0) {
            gcd = i;
            return gcd;
        }
    }
}

int gcd(int a, int b){                  //  using difference
    if (a == b)
        return a;
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}


int gcd1(int a, int b){              //  using modulus
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
int main(){
	int a = 1;
	int b = 2;

	cout<<GCD(30,75)<<endl;


}