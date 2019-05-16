/*
Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.
Example:
Input: 	
1 2 3
4 5 6
7 8 9
Return the following :
[[1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]]
Input : 
1 2
3 4
Return the following  : 
[[1],
  [2, 3],
  [4]]
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > diagonal(vector<vector<int> > &a) {
	int size = a.size();
	vector<vector<int> > b;
	vector<int> row;
	for(int i = 0; i<size; i++){
		int x = 0;
		int y = i;
		while(y>=0 && x<=i){
			row.push_back(a[x][y]);
			y--;
			x++;
		}
		b.push_back(row);
		row.clear();
	}

	for(int i = 1; i<size; i++){
		int s = i;
		int t = size-1;
		while(t>0 && s<=size-1 && s>0){
			row.push_back(a[s][t]);
			t--;
			s++;
		}
		b.push_back(row);
		row.clear();
	}

	return b;
}

int main(){
    vector<vector<int> > a = {{0}};
    vector<vector<int> > b = diagonal(a);
    cout<<a.size()<<endl;
    cout<<b[0].size()<<endl;
    
    for(int i = 0; i<b.size(); i++){
    	cout<<" [ ";
    	for(int j=0; j<b[i].size(); j++){
    		cout<<" "<<b[i][j]<<" ";
    	}
    	cout<<" ] "<<endl; 
    }

}