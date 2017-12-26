#include <iostream>
using namespace std;


void merge(int A[],int p,int q,int r){
	
	int n1 = q-p+1;
	int n2 = r-q; 

	int a[n1+1];
	int b[n2+1];

	for( int i=0; i<n1; i++){
		a[i] = A[p+i];
	}

	for( int j=0; j<n2; j++){
		b[j] = A[q+j+1];
	}

	a[n1+1] = 'a';  //why to add one more
	b[n2+1] = 'a';	// why to add one more

	int i = 0;
	int j = 0;
	for(int k=p;k<=r;k++){
		if(a[i]<=b[j]){
			A[k] = a[i];
			i++;
		}else if(a[i]>b[j]){
			A[k] = b[j];
			j++;
		}
	}

	
	
}

void merge_sort(int A[],int p, int r){
	if(p<r){
		int q = (p+r)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}

int main(){

	int A[20] = {5,8,4,6,9,1,7,5,7,2,4,5,7,1,2,3,6,5,8,9};
	merge_sort(A,9,16);

	for(int i = 0;i<20;i++){
		cout<<A[i]<<endl;
	}

	return 0;
}