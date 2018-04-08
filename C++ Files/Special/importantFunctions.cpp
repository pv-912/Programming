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

int main(){
	int a = 1;
	int b = 2;

	swap(a,b);
	cout<<a<<" "<<b<<endl;

	cout<<GCD(30,75)<<endl;


}