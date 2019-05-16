#include <iostream>
#include <climits>
using namespace std;

int left(int i){return 2*i+1;}
int right(int i){return 2*i+2;}
int parent(int i){return (i-1)/2;}

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i){
	int l = left(i);
	int r = right(i);
	int largest = i;

	if(l<n && arr[largest] < arr[l])
		largest = l;
	if(r<n && arr[largest] < arr[r])
		largest = r;

	if(i!=largest){
		swap(&arr[i], &arr[largest]);
		i = parent(i);	
	}
	
}

void heapSort(int arr[], int n){
	for(int i = n-1; i>=0; i--)
		heapify(arr, n,i);

	for(int i = n-1; i>=0; i--){
		swap(arr[i],arr[0]);
		heapify(arr, i, 0);
	}
}


int main(){
	int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
	for(int i = 0; i<n; i++)
		cout<<arr[i]<<" ";

}