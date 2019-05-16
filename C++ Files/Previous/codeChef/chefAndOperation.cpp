#include<iostream>
#include<bits/stdc++.h>

#define eb emplace_back
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

void solve(){
	int n;
	cin>>n;
	int A[n], B[n];
	for (int i = 0; i < n; ++i)
		cin>>A[i];
	for (int i = 0; i < n; ++i)
		cin>>B[i];
	for (int i = 0; i < n; ++i){
		if(A[i]>B[i]){
			cout<<"NIE"<<endl;
			return;
		}
		A[i] = B[i] - A[i];
	}
	int k = A[0], index = 0;
	while(index<n-2){
		if(A[index] == 0){
			index++;
		}
		else{
			k = A[index];
			A[index] = 0;
			A[index+1] -= k*2;
			A[index+2] -= k*3;
			if(A[index+1] <0 || A[index+2] <0){
				cout<<"NIE"<<endl;
				return;
			}
			for (int i = 0; i < n; ++i)
				cout<<A[i]<<" ";
			index++;
		}
	}

	if(index == n-2 && A[index]==0 && A[index] == 0)
		cout<<"TAK"<<endl;
	else
		cout<<"NIE"<<endl;


}

int main(){
	FIO
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}