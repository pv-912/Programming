#include<iostream>
#include <string>
using namespace std;

int lps(string seq, int start, int end){
	if( start == end)
		return 1;
	if(seq[start] == seq[end] && start+1 == end)
		return 2;
	if(seq[start] == seq[end])
		return lps(seq, start+1, end-1) +2;
	else 
		return max(lps(seq, start, end-1), lps(seq, start+1, end));

}

int lpsDP()(string seq, int start, int end){
	int arr[i][j];
	int len = seq.length();
	for(int i =0 ; i<len; i++){
		arr[i][i] = 1;
	}

	for(int i =0 ; i<len; i++){
		for(int j = 0 ; j<len; j++){
			if(i ==0 || j == 0){
				arr[i][j] = 0;
			}
			if(i+1 == j && seq[i] == seq[j]){
				arr[i][j] = arr[i][j-1] +2;
			}
			if(seq[i] == seq[j]){
				arr[i][j] = arr[i][j-1]
			}
		}
	}
}

 int main(){
 	string seq = "GEEKSFORGEEKS"; 
    int n = seq.length(); 
    cout<<"The length of the LPS is "<< lps(seq, 0, n-1)<<endl; 
    cout<<"The length of the LPS is "<< lpsDP(seq, 0, n-1)<<endl; 
    getchar(); 
    return 0; 
 }