#include<iostream>
using namespace std;

void solve(){
	int n;
	cin>>n;
		int arr[n];
		bool a = false;
		long long sum = 0;
		for(int i = 0 ; i<n; i++){
			cin>>arr[i];
			sum += arr[i];
			if(arr[i] == 1){
				a = true;
			}
		}
		if(a==true){
			cout<<sum<<endl;
		}
		else{
			cout<<(sum/2)<<endl;
		}
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}