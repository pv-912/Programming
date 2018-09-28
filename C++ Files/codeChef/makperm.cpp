#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	int arr[n];
	set<int> a;
	int count = 0;
	for(int i= 0; i<n; i++){
		cin>>arr[i];
		if(arr[i]>n){
			count++;
		}
		else if(a.find(arr[i]) == a.end()){
			a.insert(arr[i]);
		}
		else if(a.find(arr[i]) != a.end()){
			count++;
		}
	}
	cout<<count<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}