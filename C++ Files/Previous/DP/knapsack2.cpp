// Doubt in line 26 as [j-wt[i-1]] will be negative index of an array

#include <iostream>

using namespace std;


int knapSack(int W, int wt[], int val[], int n){
	if(n==0 || W==0){
		return 0;
	}
	if(wt[n-1] > W)
		return knapSack(W, wt,val,n-1);
	else {
		return max(knapSack(W - wt[n-1], wt,val, n-1) + val[n-1], knapSack(W, wt,val, n-1));
	}
}

int knapSackDP(int W, int wt[], int val[], int n){
	int res[n+1][W+1];
	for(int i = 0; i<=n; i++){
		for(int j= 0; j<=W; j++){
			if(i==0 || j ==0)
				res[i][j] = 0;
			else if(W>=wt[i-1])
				res[i][j] = max( val[i-1] + res[i-1][j-wt[i-1]] , res[i-1][j] );
			else
				res[i][j] = res[i-1][j];
		}
	}
	return res[n][W];
}

 int main(){
 	int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    cout<< knapSack(W, wt, val, n)<<endl; 
    cout<< knapSackDP(W, wt, val, n)<<endl; 
    return 0; 

 }