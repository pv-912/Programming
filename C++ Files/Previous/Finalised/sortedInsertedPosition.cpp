/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.

[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/
#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &a, int b) {
	int size = a.size();
	int low = 0, high = size-1;
	int first = -1;
	if(a[high] < b){
        return high+1;
    }    
    else if(a[0] > b){
        return 0;
    }
	while(low<=high){
		int mid = low + (high-low)/2;
		if(a[mid] == b){
			return mid;
		}
		else if(a[mid] > b){
			high = mid - 1;
		}
		else if(a[mid] < b){
			low = mid + 1;
			// cout<<mid<<endl;
		}else{
			return mid;
		}
	}
}

int main() {
	vector<int> a = {3, 4, 18, 19, 20, 27, 28, 31, 36, 42, 44, 71, 72, 75, 82, 86, 88, 97, 100, 103, 105, 107, 110,
	 116, 118, 119, 121, 122, 140, 141, 142, 155, 157, 166, 176, 184, 190, 199, 201, 210, 212, 220, 225, 234, 235,
	  236, 238, 244, 259, 265, 266, 280, 283, 285, 293, 299, 309, 312, 317, 335, 341, 352, 354, 360, 365, 368, 370, 
	  379, 386, 391, 400, 405, 410, 414, 416, 428, 433, 437, 438, 445, 453, 457, 458, 472, 476, 480, 485, 489, 491,
	   493, 501, 502, 505, 510, 511, 520, 526, 535, 557, 574, 593, 595, 604, 605, 612, 629, 632, 633, 634, 642, 647, 
	   653, 654, 656, 658, 686, 689, 690, 691, 709, 716, 717, 737, 738, 746, 759, 765, 775, 778, 783, 786, 787, 791, 
	   797, 801, 806, 815, 820, 822, 823, 832, 839, 841, 847, 859, 873, 877, 880, 886, 904, 909, 911, 917, 919, 937, 
	   946, 948, 951, 961, 971, 979, 980, 986, 993 };
	cout<<searchInsert(a,902);
	return 0;

}
