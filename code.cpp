/*
	Author: Prem Ukkoji
*/

#include <bits/stdc++.h>
using namespace std;

// shortcuts
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef priority_queue<ll> max_heap;
typedef priority_queue<ll, vector<ll>, greater<ll>> min_heap;

// debugging
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbgall(__VA_ARGS__)
void dbgall() { cout << endl; }
template<typename Head, typename... Tail>
void dbgall(Head H, Tail... T) { cout << ' ' << H; dbgall(T...); }
#define dbg2d(arr) for(ll i=0;i<arr.size();i++){for(ll j=0;j<arr[i].size();j++){cout<<arr[i][j]<<" ";}cout<<"\n";}cout<<"\n";
#define dbg1d(arr) for(auto ele: arr){cout<<ele<<" ";}cout<<"\n";

#define read1D(arr) for(auto &ele: arr){cin>>ele;}

#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define tc ll T;cin>>T;while(T--)
#define inf INT_MAX
#define linf LLONG_MAX
#define MOD 1000000007
#define PI 3.141592653589793
#define endl "\n"

#define flush cout.flush()
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)
#define csb(n) __builtin_popcountll(n)
#define cb(n) floor(log2(n)) + 1
#define vi vector<int>
#define vb vector<bool>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(arr) arr.begin(), arr.end()
#define search(mp, n) !!(mp.find(n) != mp.end())
#define rep(i, a, b)  for (ll i = a; i < b; i++)
#define iter(it, con)  for (auto it=con.begin(); it!=con.end(); it++)

void setio() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

signed main() {
	clock_t p_start = clock();
	io;
	setio();

	tc{
		ll n;
		cin >> n;
	}

	clock_t p_end = clock();
	cerr << "Time : " << (double)(p_end - p_start) / (double)CLOCKS_PER_SEC << " sec  ";
	return 0;
}
