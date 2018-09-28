#include<iostream>
using namespace std;

void fibo(int n){
	int arr[n+1];
	arr[0] = 1;
	arr[1] = 1;
	for(int i=2; i<n; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	cout<<arr[n-1]<<endl;
}

int main(){
	int n;
	cin>>n;
	fibo(n);
}