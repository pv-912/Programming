#include <iostream>
#include <cmath>

// using namespace std;
#define MAX 1000

bool hash[MAX+1][2];

bool search(int n){
	if(n>=0){
		if( hash[n][0] == 1)
			return true;
		return false;
	}

	if(abs(hash[n][1])==1)
		return true;
	return false;
}

void insert(int a[], int size){
	for(int i=0; i<size; i++){
		if(a[i]>=0){
			hash[a[i]][0] = 1;
		}
		else
			hash[abs(a[i])][1] =1;
	}
}

int main(){
	int a[] = { -1, 9, -5, -8, -5, -2 };
	int size = sizeof(a)/sizeof(a[0]);
	insert(a, size);
	std::cout<<search(9);
}