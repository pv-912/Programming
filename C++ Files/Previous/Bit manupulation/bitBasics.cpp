#include <iostream>

using namespace std;

int countSetBits(int n){
    if (n == 0)
        return 0;
    else
        return (n & 1) + countSetBits(n >> 1);
}

void addOneToNumber(int x){
	int m = 1;
	while( x & m ){
		x = x ^ m;
		m = m << 1;
	}
	x = x ^ m;
	cout<<x<<endl;
}

int multiplyBy3point5(int a){
	cout<< a + (a<<1) + (a>>1)<<endl;
}

int turnOffRightMostSetBIt(int x){
	cout<< (x & (x-1)) <<endl;
}

int main(){
	int a;									// add one to number
	cin>>a;
	// addOneToNumber(a);

	// multiplyBy3point5(a);
	// turnOffRightMostSetBIt(a);
	// isGivenNumberIsPowerOf4(a);
	subtract1ToNumber(a);
}