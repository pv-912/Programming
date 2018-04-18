
#include <iostream>
#include<bits/stdc++.h>

using namespace std;


int binarySearch(int a, int start, int end){
	int mid = floor(start + (end-start)/2);
	while(start<=end){
		if(mid <= (a/mid) && (mid+1) > a/(mid+1) ){
			return mid;
		}else if(mid < a/mid){
			start = mid +1;
			return binarySearch(a,mid+1,end);
		}else if(mid>a/mid){
			end = mid -1;
			return binarySearch(a,start,mid - 1);
		}
	}
	return mid;
}


int sqrt(int a){
	if(a==0){
		return 0;
	}else if(a==1){
		return 1;
	}else{
		return binarySearch(a,0,a);
	}
}

int main() {
	cout<<sqrt(256);
	return 0;

}
