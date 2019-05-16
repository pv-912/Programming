#include <iostream>
using namespace std;

long int factorial(long int *a){
	if(*a>1){
		 long int b = *a-1;

		*a = *a * factorial(&b);
	}
	return *a;
} 

int main(){

	long int a;
	cin>>a;
	long int b = factorial(&a);
	cout<<b<<endl;

}