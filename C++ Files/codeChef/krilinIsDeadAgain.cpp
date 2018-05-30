#include <bits/stdc++.h>
using namespace std;


int gcd(int a, int b)
{
    // base case
    if (a == b)
        return a;
 
    // a is greater
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}
 
// Function to return LCM of two numbers
int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}
 
double findMedian(int a[], int n){
    sort(a, a+n);
    if (n % 2 != 0)
       return (double)a[n/2];
     
    return (double)(a[(n-1)/2] + a[n/2])/2.0;
}

double showMedian(int *array, int size){



    int middle;

    double average, median;

 

    middle = size / 2.0;
    if (size % 2)
    {
        median = (array[middle] + array[middle + 1]) / 2.0;
        return median;
    }
    else
    {
        median = array[middle + 0] / 1.0;
        return median;
    }
    return median;
}


int findMode(int * arr, int arraySize)
{
    map<int, int> modeMap;
    for (int i = 0; i < arraySize; ++i) {
        ++modeMap[arr[i]];
    }

    auto x = std::max_element(modeMap.begin(), modeMap.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second; });

    return x->first;
}

int main(){
	int t;
	cin>>t;
	while(t--){
        int n,q;
		cin>>n>>q;
        int arr[n];
        for (int i = 0; i < n; ++i){
            cin>>arr[i];
        }
        while(q--){
            int p,l,r;
            cin>>p>>l>>r;
            if(p==1){
                int *b = new int[r-l];
                std::copy(arr + l-1, arr + r-1, b);
                double med= (double)findMedian(b, r-l);
                int median =  floor(med);
                int mode= findMode(b, r-l);
                int L = lcm(median, mode);
                cout<<med<<" "<<mode<<" "<<median<<" "<<L<<endl;
            }
            else if(p==2){
                arr[l] = r;
            }
        }
	}
}