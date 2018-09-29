#include<iostream> 
using namespace std;

void solve(){
	int n,k;
	cin>>n>>k;
	int arr[n+1][k+1];

	for(int i=0; i<=n; i++){
		for(int j= 0; j<=min(i,k); j++){
			if(j==0 || j==i)
				arr[i][j] = 1;
			else
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
		}
	}
	cout<<arr[n][k]<<endl;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}