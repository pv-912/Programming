/*
Implement pow(x, n) % d.
In other words, given x, n and d,
find (xn % d)
Note that remainders on division cannot be negative. 
In other words, make sure the answer you return is non negative.
Input : x = 2, n = 3, d = 3
Output : 2
2^3 % 3 = 8 % 3 = 2.
*/

#include <iostream>
// #include<bits/stdc++.h>
using namespace std;

int pow(int x, int n, int d) {
	if(x == 0){
		return 1;
	}
    long long ans = 1;
    if(n>0){
    	if(n%2 == 0){
    		ans = ((x*x)%d)*pow(x,n-2,d);
    	}
	    else{
	    	ans = (x%d)*pow(x,n-1,d);
	    }
	}
    ans = ans % d;
    return ans;
}


int main() {
	cout<<pow(71045970,415484,64735492);

	return 0;

}
