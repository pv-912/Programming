#include <iostream>
using namespace std;

void maxDifference(int A[], int size){

	int diff=0;

	for(int i=0; i<size; i++){
		for(int j=size; j>i; j--){
			int b = A[i]-A[j];
			if(b<0){
				b = b-(b*2);
				if(b>diff){
					diff = b;
				}
			}
		}
	}

	cout<<diff<<endl;
}

void minDifference(int A[], int size){

	int diff=100;

	for(int i=0; i<size; i++){
		for(int j=size; j>i; j--){
			int b = A[i]-A[j];
			if(b<0){
				b = b-(b*2);
				if(b<diff){
					diff = b;
				}
			}
		}
	}

	cout<<diff<<endl;
}


int main(){
	int a[] = {5,10,3,7,2,8};
	int a1[] = {54,78,569,52,856,915,874,236,896,541,258,793,1125,1048,1256,1039};
	int size = 6;
	int size1 = 16;

	maxDifference(a,size);
	minDifference(a,size);
	maxDifference(a1,size1);
	minDifference(a1,size1);
	return 0;
}