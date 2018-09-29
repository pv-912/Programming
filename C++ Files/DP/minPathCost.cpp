#include<iostream>
#include<limits.h>
#define R 3 
#define C 3 
using  namespace std; 
int minCost(int cost[R][C], int i , int j ){
	if(i>=R || j>= C)
		return INT_MIN;
	else if(i == R-1 && j == C-1){
		return cost[i][j];
	}
	else
		return (min( minCost(cost, i++, j), min( minCost(cost, i, j++), minCost(cost,i++,j++) )  ) + cost[i][j]);
}

int main(){
	 int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} };
                      int i = 0, j = 0; 
       cout<<minCost(cost, i, j)<<endl;
}