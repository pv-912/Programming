#include <iostream>
using namespace std;

int search(int A[], int size, int x){
	int key = 5;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if( A[i] + A[j] == x){
				key = 10;
			}else{
				continue;
			}
		}
	}

	return key;
}

int main(){
	int size = 6;
	int x = 22;
	int a[size] = {50,45,87,62,12,10};

	int ans = search(a, size, x);
	if(ans==10){
		cout<<"Yes, There Exit Pair."<<endl;
	}else{
		cout<<"No, There Is No Pair."<<endl;
	}
	return 0;
}