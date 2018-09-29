#include<iostream>
#include<limits.h>
using  namespace std; 

int count(int arr[],int size,int m, int sum, int realSum){
	if(sum == realSum)
		return 1;
	if(sum<realSum)
		return 0;
	if(sum>realSum && size-1>m)
		return 0;
	int k = m+1, l = realSum + arr[m];
	return count(arr,size,k, sum, realSum) + count(arr,size,m,sum,l);
}

int main(){
	 int i=0, j; 
    int arr[] = {1, 2, 3}; 
    int m = 	sizeof(arr)/sizeof(arr[0]);
    int realSum = 0; 
    cout<<count(arr, m,i, 4,realSum)<<endl; 
}