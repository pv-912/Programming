
/* not completed yet */

#include <iostream>
#include <stack>
#include <queue>
#include <limits.h>
using namespace std;

int min(int a, int b){
	if(a>b){
		return b;
	}
	return a;
}

int trap( vector<int> &a) {
	
	vector<int>::iterator it;
	int x = a[0];
	int i=1;
	while(x<=a[++i]){
		x = a[i];
	}
	i--;
	int initialI = i;
	int count = 0,countToSubtract = 0;
	for(i; i<a.size(); i++){
		if(x<=a[i]){
			count = x*(i- initialI-1) - countToSubtract;    // -1 as a[i] add first element also
			initialI = i;
			x = a[i];
			countToSubtract = 0;
		}
		countToSubtract += a[i];
	}

	// while(x>a[i]){
	// 	i++;
	// }


	return i;

	// for(it = a.begin(); it != a.end(); it++){
	// }
	

}

int main(){
	vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};

	cout<<endl<<trap(a);
}