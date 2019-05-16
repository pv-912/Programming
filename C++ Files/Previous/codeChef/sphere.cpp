#include <iostream>
#include <cmath>
#include<iomanip>
#include<math.h>
using namespace std;
int main() {
	int T;
	cin>>T;
	while(T--){
		long long int x1,y1,z1,x2,y2,z2,d1,d2,d3,x3,y3,z3,r;
    	cin>>x1>>y1>>z1>>x2>>y2>>z2>>d1>>d2>>d3>>x3>>y3>>z3>>r;
    	long long int a = pow((x2 - x1),2) + pow((y2 - y1),2) + pow((z2 - z1),2);
    	long long int b = ((x2 - x1) * (x1 - x3) + (y2 - y1) * (y1 - y3) + (z2 - z1) * (z1 - z3) );
    	long long int c = (pow(x3,2) + pow(y3,2) + pow(z3,2) + pow(x1,2) + pow(y1,2) + pow(z1,2) - 2*(x3 *x1 + y3* y1 + z3 *z1) - pow(r,2));
    	long long int e = d1*(x1-x3) + d2*(y1-y3) + d3*(z1-z3);
    	long long int f = d1*(x2-x1) + d2*(y2-y1) + d3*(z2-z1);
    	long long int g = pow(d1,2) + pow(d2,2) + pow(d3,2);
 
     	long long int a1 = c*g - pow(e,2);
     	long long int b1 = 2*(c*f - b*e);
    	long long int c1 = a*c - b*b;
    	double ans1, ans2;
    	cout<<fixed<<setprecision(10);
    	if(a1 == 0){
    		ans1 = (double)abs(c1/(b1)); 
    		ans1 = (floor(ans1*100000000))/100000000;
    		cout<<ans1<<endl;
    		return 0;
    	}

    	ans1 = (double)((-b1 + sqrt(b1*b1 - 4*a1*c1))/(2*a1));
    	ans2 = (double)((-b1 - sqrt(b1*b1 - 4*a1*c1))/(2*a1));
    	ans1 = (floor(ans1*100000000))/100000000;
    	ans2 = (floor(ans2*100000000))/100000000;
    	// cout<<fixed<<setprecision(10)<<a<<" "<<b<<" "<<c1<<" "<<e<<" "<<f<<" "<<g<<" "<<a1<<" "<<b1<<" "<<c1<<" "<<ans1<<" "<<ans2<<" "<<endl;

    	if(ans1<=ans2){
    		if(ans1>0.000000000001){
    			cout <<ans1<< endl;
    		}
    		else{
    			cout <<ans2<< endl;
    		}
    	}
    	else if(ans2<ans1){
    		if(ans2>0.00000000001){
    			cout <<ans2<< endl;
    		}
    		else{
    			cout <<ans1<< endl;
    		}
    	}
	}
}