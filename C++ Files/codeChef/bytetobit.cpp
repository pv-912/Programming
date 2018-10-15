#include<iostream>
#include<bits/stdc++.h>

#define eb emplace_back
#define pq priority_queue
#define umap unordered_map
#define pb(x) push_back(x)
#define pf(x) push_front(x)
#define ppb(x) pop_back(x)
#define ppf(x) pop_front(x)
#define lwr(x) lower_bound(x)
#define upr(x) upper_bound(x)
#define mp(x, y) make_pair(x, y)
#define all(x) x.begin(),x.end()
#define clr(a,b) memset(a,b,sizeof a)
#define fr(i,n) for(int i=0; i<n;++i)
#define fr1(i,n) for(int i=1; i<=n; ++i)
#define prn1(x) cout<<x<<"\n";
#define prn2(x, y) cout<<x<<" "<<y<<"\n";
#define prn3(x, y, z) cout<<x<<" "<<y<<" "<<z<<"\n";
#define prn4(x, y, z, a) cout<<x<<" "<<y<<" "<<z<<" "<<a<<"\n";
#define FIO ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define mod 1000000007

//setbase - cout << setbase (16)a; cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 <<endl;prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val


using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd; 
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pil> vpil;
typedef vector<pli> vpli;

void solve(){
	int n;
	cin>>n;
	int bit = 0, byte = 0,  nibble = 0;
	int x = n/27;
	int rest = n%27;
	ll res = pow(2,x);
	if(rest>0 && rest <= 2 ){
		bit = res;
	}
	else if(rest>2 && rest <= 10)
		nibble = res;
	else
		byte = res;
	prn3(bit,nibble, byte);
	// cout<<bit<<" "<<nibble<<" "<<byte<<endl;
}

int main(){
	FIO
	int t;
	cin>>t;
	while(t--){
		solve();
	}
}