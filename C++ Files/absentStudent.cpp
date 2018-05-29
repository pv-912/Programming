
/* not completed yet  */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> studentAbsent(vector<int> &a, int n){
    vector<int> b;
    sort(a.begin(), a.end());
    int i = 0;
    int diff;
    while(i<n-1){
        if((a[i] + 1) < a[i + 1]){
            diff = a[i + 1 ] - a[i];
            for(int j = 0; j<diff-1; j++){
                b.push_back(a[i] + j + 1);
            }
        }
        i++;
    }
    return b;
}


int main() {
    int n;
    cin>>n;
    if(n>=100 || n<0){
        return 0;
    }
    vector<int> a = {1,3,4,8,8,8,8,8,9,10,15,15,15,15,15};
    vector<int> x = studentAbsent(a,n);
    for (int i = 0; i < x.size(); i++) {
        cout<<x[i];
    }
}