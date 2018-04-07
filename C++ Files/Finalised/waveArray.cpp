/*
Given an array of integers, sort the array into a wave like array and return it, 
In other words, arrange the elements into a sequence such that a1 >= a2 <= a3 >= a4 <= a5.....

Example

Given [1, 2, 3, 4]

One possible answer : [2, 1, 4, 3]
Another possible answer : [4, 1, 3, 2]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
}

vector<int> wave(vector<int> &c) {
    int size = c.size();
    int q=0;
    sort(c.begin(), c.end());

	if (c.size() % 2 != 0 ){
		while(q<c.size()-1){
			swap(c[q], c[q+1]);
			q = q+2;
	    }	
	}
	else{
		while(q<c.size()){
			swap(c[q], c[q+1]);
			q = q+2;
    	}
	}
    return c;
}

int main(){
    vector<int> a = {6,0,6,12};
    vector<int> b;
    b = wave(a); 
    for(int i=0; i<b.size(); i++){
    	cout<<" "<< b[i]<<" ";
    }
}