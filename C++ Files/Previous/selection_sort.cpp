#include <iostream>
using namespace std;

void selection_sort(int A[],int size){
	
}

// void print_array(int A[], int size){
// 	for(int i=0; i<size; i++){
// 		cout<<A[i]<<endl;
// 	}
// }

int main(){

	int A[6]  = {5,87,56,98,14,25};
	int size = 6;

	for(int i=0; i<size; i++){
		
		int temp;

		for(int k=0; k < size; k++){
			if(temp > A[k+1]){
				temp = A[i];
				A[k+1] = A[i];
				temp = A[k+1];
			}

			else{
				continue;
			}
		}
		A[i] = temp;
	}

	for(int j=0; j<size; j++){
		cout<<A[j]<<endl;
	}
	// selection_sort(A,size);
	// print_array(A,size);
	return 0;
}