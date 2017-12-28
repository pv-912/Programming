#include <iostream>
using namespace std;

unsigned long int factorial(int *a){
	if(*a>1){
		unsigned long int b = *a-1;

		*a = *a * factorial(&b);
	}
	return *a;
} 

int main(){

	int a;
	cin>>a;
	unsigned long int b = factorial(&a);
	cout<<b<<endl;

}