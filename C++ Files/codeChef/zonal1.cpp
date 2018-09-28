#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long n;
	cin>>n;
	long long arr[n];
	for(long long i=0; i<n; i++)
		cin>>arr[i];
	sort(arr, arr+n);
	long long res = 0, temp = 0;
	for(long long i= 0; i<n; i++){
		temp = arr[i]*(n-i);
		res = max(res, temp);
	}
	cout<<res<<endl;
}