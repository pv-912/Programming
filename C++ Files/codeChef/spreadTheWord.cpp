#include<iostream>
#include<bits/stdc++.h>

#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

using namespace std;
void solve(){
	int n;
	cin>>n
;	int arr[n];
	for(int i = 0; i<n; i++){
		cin>>arr[i];
	}

	long long int res = 1;
	long long int people = 1 +arr[0];
	long long sum = arr[0];
	int index = 1;
	while(people<n){
		long long int temp = people;
		long long int k = sum;
		for(int i = index; i<temp;i++){
			people += arr[i];
			sum+=arr[i];
		}
		index = temp;
		people += k; 
		res++;
	}
	cout<<res<<endl;
}

int main(){
	FIO
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}