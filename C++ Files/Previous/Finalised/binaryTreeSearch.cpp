/*

Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.
*/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

// int binarySearch(int a[], int x, int size){
// 	int low = 0, high = size-1;
// 	while(low<=high){
// 		int mid = low + (high-low)/2;
// 		if(a[mid] == x){
// 			return mid;
// 		}
// 		else if(a[mid] > x){
// 			high = mid - 1;
// 		}
// 		else{
// 			low = mid + 1;
// 		}
// 	}
// 	return -1;
// }

int findCount( vector<int> &a, int b) {
	int size = a.size();
	int low = 0, high = size-1;
	int first = -1;
	int e = 0;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(a[mid] == b){
			first = mid;
			if(e==0){
				high = mid - 1;
			}
			continue;
		}
		else if(a[mid] > b){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	low = 0, high = size-1;
	int last = -1;
	e = 1;
	while(low<=high){
		int mid = low + (high-low)/2;
		if(a[mid] == b){
			last = mid;
			if(e==1){
				low = mid + 1;
			}
			continue;
		}
		else if(a[mid] > b){
			high = mid - 1;
		}
		else{
			low = mid + 1;
		}
	}
	if(first== -1){
		return 0;
	}
		return last-first+1;

}


int main() {
	vector<int> a = {1,2,3,8};
	cout<<findCount(a,5);

	return 0;

}
