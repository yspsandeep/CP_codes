#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
#define ll long long 
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

/*--------------------------------------------------------------------------------------------*/

#define MOD (ll)(1e9+7)
const int N = 1e7;

 vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
 
 ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
 
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
/*--------------------------------------------------------------------------------------------*/


void solve(){
	int t;
	cin>>t;
	while(t-->0){
	ll n;cin>>n;
	vector<ll>v(n);
	
	for(auto &it:v){
		cin>>it;
	}
	
	//NGR 
	stack<int> st;
	vector<int> ans(n);
	for(int i=n-1;i>=0;i--){
		
		while(!st.empty() && v[st.top()]<= v[i]){ // compare using indices.
			st.pop();
		}
		
		if(st.empty()){
			ans[i] = n;   // End of the array.
		}
		else{
			ans[i] = st.top();
		}
		st.push(i);		// Pushing vector Indexes instead of values
	}
	
	for(auto &it:ans){
		cout<<it<<" ";
	}
	cout<<endl;
	
	}
}

int main(){
	fastio();
	auto start1 = high_resolution_clock::now();
      solve();
      auto stop1 = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop1 - start1);
      #ifndef ONLINE_JUDGE
      cerr << "Time: " << duration.count() / 1000 << endl;
      #endif
}