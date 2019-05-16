/*
Write an efficient algorithm that searches for a value in an m x n matrix.
This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than or equal to the last integer of the previous row.
Example:
Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return 1 ( 1 corresponds to true )
Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int x, int size){
	int low = 0, high = size-1;
	int mid = 0;
	while(low<=high){
		mid = low + (high-low)/2;
		if(a[mid] == x){
			return mid;
		}
		else if(a[mid] > x){
			high = mid - 1;
		}
		else if(a[mid] < x){
			low = mid + 1;
		}
	}
	// if(mid == 0){
	// 	return mid;
	// }
	// return mid -1 ;
}
bool binarySearchOutput(int a[], int x, int size){
	int low = 0, high = size-1;
	int mid = 0;
	while(low<=high){
		mid = low + (high-low)/2;
		if(a[mid] == x){
			return true;
		}
		else if(a[mid] > x){
			high = mid - 1;
		}
		else if(a[mid] < x){
			low = mid + 1;
		}
	}
	return false;
	// if(mid == 0){
	// 	return mid;
	// }
	// return mid -1 ;
}

int searchMatrix(vector<vector<int> > &a, int b) {
    int col = a[0].size();
    int row = a.size();
    int c[row];
    int d[col];

    for(int i=0;i<row;i++){
   	    c[i] = a[i][0];
    }

    int mainRow = binarySearch(c, b, row);
    bool mainRow1 = binarySearchOutput(c, b, row);
    bool presency;
    // cout<<mainRow;
    if(mainRow1 == 1){
    	return 1;
    	// cout<<"hey"<<endl;
    }
    else{
    	for(int i=0;i<col;i++){
    		if(mainRow==0){
	   	    	d[i] = a[mainRow][i];
    		}else{
	   	    	d[i] = a[mainRow-1][i];
	   		}
	    	
	    }
	    presency = binarySearchOutput(d,b,col); 

    }
    return presency;
   // for(int i = 0;i<row;i++){
   	// cout<<endl<<c[i]<<" ";
   // }
}


int main() {
	vector<vector<int> > a = { {2, 4, 4, 4, 5, 5, 6},
  {10, 11, 12, 13, 13, 14, 15},
  {16, 25, 25, 26, 28, 28, 30},
  {30, 32, 33, 39, 39, 40, 41},
  {44, 44, 47, 49, 51, 55, 57},
  {57, 60, 60, 61, 61, 62, 63},
  {64, 65, 66, 67, 68, 71, 71},
  {75, 77, 77, 77, 78, 79, 80},
  {81, 83, 84, 85, 86, 88, 88},
  {91, 92, 93, 93, 95, 95, 98}};


	cout<<searchMatrix(a,0);

	return 0;

}
