#include <iostream>

using namespace std;

int main(){
	int a[6] = {24,18,15,65,89,21};
	int size = 6;

	for(int i=1;i<=size;i++){
		int temp ;
		temp = a[i];

		while(temp<a[i-1]and i>0){
			a[i] = a[i-1];
			i--;
		}
		a[i] = temp;
	}

	for(int k=0; k<size;k++){
		cout<<a[k]<<endl;
	}
	return 0;
}