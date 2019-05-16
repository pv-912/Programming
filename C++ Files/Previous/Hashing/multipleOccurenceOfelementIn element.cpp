#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <iterator>
#include <unordered_set>
using namespace std;

// void groupElements(int arr[], int n){
//    unordered_map<int, int> m;
//    unordered_map<int, int> :: iterator it;

//    for(int i = 0; i<n; i++){
// 	   if(m.find(arr[i]) !=m.end()){
// 	   		it  = m.find(arr[i])++;
// 	   		*it++;
// 	   }
// 	   else{
// 	   		m.insert(pair <int, int> (arr[i],1));
// 	   }
//    }

//    for(int i = 0; i<n; i++){
//    	int count = m.find(arr[i])!=m.end();
//    	cout<<count<<" "<<endl;
//    	if(count!=0){
//    		for (int j=0; j<count; j++)
//                    cout<<arr[i] << " ";

//         m.erase(arr[i]);
//    	}
//    }
// }


void groupElements(int a[], int n){
 unordered_map<int, int> m;
 unordered_map<int, int> :: iterator it;
 int k=0,j=0;

 for(int i=0;i<n;i++){
    m[a[i]]++;
 	// cout<<a[i]<<" ";
 }
 cout<<m[10]<<endl;
 for(it = m.begin();it!=m.end();it++){
 	j=0;
 	cout<<it->first<<" ";
   while(j<it->second){
     a[k] = it->first;
     j++;
     k++;
   }
 }
 for(int i=0;i<n;i++)
     cout<<a[i]<<" ";
}

int main(){
    int arr[] = {4, 6, 9, 2, 3, 4, 9, 6, 10, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    groupElements(arr, n);
    return 0;
}