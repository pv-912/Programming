#include <iostream>
using namespace std;


void merge(int A[],int p,int q,int r){
	
	int n1 = q-p+1;
	int n2 = r-q; 

	int a[n1];
	int b[n2];

	for( int i=0; i<n1; i++){
		a[i] = A[p+i];
	}

	for( int j=0; j<n2; j++){
		b[j] = A[q+j+1];
	}

	// a[n1+1] = 'a';  //why to add one more
	// b[n2+1] = 'a';	// why to add one more

	int i = 0;
	int j = 0;
	int k = p;
	for(k;k<r;k++){
		if(a[i]<=b[j]){
			A[k] = a[i];
			i++;
		}else if(a[i]>b[j]){
			A[k] = b[j];
			j++;
		}
	}

	while(i<n1){
		A[k] = a[i];
		i++;
		k++;
	}

	while(j<n2){
		A[k] = a[j];
		j++;
		k++;
	}	
}

void merge_sort(int A[],int p, int r){
	if(p<r){
		int q = (p+(r-1))/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}

int main(){

	int A[] = {10,9,8,7,6,5,4,3,2,1,0};
	int size = sizeof(A)/sizeof(A[0]);
	for(int i = 0;i<size;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	merge_sort(A,0,size);

	for(int i = 0;i<size;i++){
		cout<<A[i]<<" ";
	}

	return 0;
}