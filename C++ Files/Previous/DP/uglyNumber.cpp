#include <iostream>
using namespace std;

void ugly(int n){
	int arr[n];
	arr[0] = 1;
	int i2 = 0,  i3 = 0, i5 = 0;
	int n2 = arr[0]*2;
	int n3 = arr[0]*3;
	int n5 = arr[0]*5;
	for(int i = 1; i<n; i++){
		arr[i] = min(n2, min(n3,n5));
		// cout<<arr[i]<<" "; 
		if(arr[i] == n2){
			i2++;
			n2 = arr[i2]*2;
		}
		if(arr[i] == n3){
			i3++;
			n3 = arr[i3]*3;
		}
		if(arr[i] == n5){
			i5++;
			n5 = arr[i5]*5;
		}
	}
	cout<<(arr[n-1])<<endl;
}

int main(){
	int n;
	cin>>n;
	ugly(n);
}