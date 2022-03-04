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
#define clz(n) __builtin_clz(n)
#define ctz(n) __builtin_ctz(n)
#define csb(n) __builtin_popcount(n)
#define cb(n) floor(log2(n)) + 1
#define vi vector<int>
#define vb vector<bool>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(arr) arr.begin(), arr.end()
#define search(mp, n) !!(mp.find(n) != mp.end())
#define rep(i,a,b)  for(ll i=a;i<b;i++)

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

	ll n, m, r, x, y;
	cin >> n >> m >> r >> x >> y;

	vector<vector<pll>> adj(n + 1);
	ll u, v, w;
	rep(i, 0, r) {
		cin >> u >> v >> w;
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}

	vll vis(n + 1, false);
	vll dist(n + 1, linf);

	dist[x] = 0;

	set<pll> nodes;
	nodes.insert({0, x});
	while (!nodes.empty()) {
		u = (*nodes.begin()).second;
		nodes.erase(nodes.begin());
		vis[u] = true;
		for (auto edge : adj[u]) {
			if (!vis[edge.second] and dist[u] != linf and
			        dist[u] + edge.first < dist[edge.second]) {
				dist[edge.second] = dist[u] + edge.first;
				nodes.insert({dist[edge.second], edge.second});
			}
		}
	}

	if (dist[y] <= m) {
		cout << "alive " << dist[y] << endl;
	} else {
		cout << "died" << endl;
	}

	clock_t p_end = clock();
	cerr << "Time : " << (double)(p_end - p_start) / (double)CLOCKS_PER_SEC << " sec  ";
	return 0;
}
