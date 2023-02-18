/*
	Author: Prem Ukkoji
*/

// optimizations
// #pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma")
// #pragma GCC optimization ("unroll-loops")

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
#define dbg1d(arr) for(auto ele: arr){cout<<ele<<" ";}cout<<"\n";
#define dbg2d(arr) for(ll i=0;i<arr.size();i++){for(ll j=0;j<arr[i].size();j++){cout<<arr[i][j]<<" ";}cout<<"\n";}cout<<"\n";

// reading input
#define io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define tc ll T;cin>>T;while(T--)
#define read1D(arr) for(auto &ele: arr){cin>>ele;}
#define read2D(arr) for(auto &row: arr){for(auto &ele: row){cin>>ele;}}

// shortcuts
#define MOD 1000000007
#define PI 3.141592653589793
#define endl "\n"
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vb vector<bool>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vvpll vector<vector<pll>>
#define clz(n) __builtin_clzll(n)
#define ctz(n) __builtin_ctzll(n)
#define csb(n) __builtin_popcountll(n)
#define msb(n) floor(log2(n))
#define isPow2(n) (n && (!(n & (n - 1))))
#define cb(n) floor(log2(n)) + 1
#define all(arr) arr.begin(), arr.end()
#define search(mp, n) !!(mp.find(n) != mp.end())
#define rep(i, a, b)  for (ll i = a; i < b; i++)
#define iter(it, con)  for (auto it=con.begin(); it!=con.end(); it++)

// bit manipulation
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))

// custom hash function
struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

// binary exponentiation
ll bin_exp(ll base, ll exp, ll mod) {
	ll res = 1LL;
	while (exp > 0) {
		if (exp % 2 == 1) res = (res * base) % mod;
		base = (base * base) % mod;
		exp /= 2;
	}
	return res;
}

// matrix exponentiation
struct Matrix {
	ll a[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	Matrix operator *(const Matrix& other) {
		Matrix product;
		for (ll i = 0; i < 3; i++) {
			for (ll j = 0; j < 3; j++) {
				for (ll k = 0; k < 3; k++) {
					product.a[i][k] += a[i][j] * other.a[j][k];
				}
			}
		}
		return product;
	}
};
// customize constMat based on your need
const ll constMat[3][3] = {{0, 1, 1}, {1, 0, 0}, {0, 1, 0}};
Matrix mat_exp(Matrix a, ll k) {
	Matrix product;
	memcpy(product.a, constMat, sizeof(constMat));
	while (k > 0) {
		if (k % 2 == 1) product = product * a;
		a = a * a;
		k /= 2;
	}
	return product;
}

// Disjoint Union Set
class DSU {
public:
	vector<ll> parent;

	DSU(ll n) : parent(n) {
		for (ll i = 0; i < n; i++)
			parent[i] = i;
	}

	void join(ll a, ll b) {
		parent[find(b)] = find(a);
	}

	ll find(ll a) {
		return a == parent[a] ? a : parent[a] = find(parent[a]);
	}

	bool check(ll a, ll b) {
		return find(a) == find(b);
	}
};

// decimal to any base
string dec_to_any(ll n, ll base) {
	string converted = "";
	if (n == 0) return "0";
	while (n > 0) {
		converted += to_string(n % base);
		n /= base;
	}
	reverse(all(converted));
	return converted;
}

// precomputing phi using division sum property
const ll PHIMAX = 1e6 + 5;
vll phi(PHIMAX);
void precompute_phi() {
	phi[1] = 1;
	for (ll i = 2; i < PHIMAX; i++) {
		phi[i] = i - 1;
	}
	for (ll i = 2; i < PHIMAX; i++) {
		for (ll j = 2 * i; j < PHIMAX; j += i) {
			phi[j] -= phi[i];
		}
	}
}

// prime numbers using sieve of eratosthenes in n*log(log(n)) TC
const int PMAX = 1e7 + 8;
bool prime[PMAX];
int spf[PMAX];
void sieve() {
	memset(prime, true, sizeof(prime));

	// smallest prime factor for all numbers till PMAX
	for (int i = 1; i < PMAX; i++) {
		spf[i] = i;
	}

	prime[0] = prime[1] = false;
	for (int i = 2; i * i < PMAX; i++) {
		if (prime[i]) {
			for (int j = i * i; j < PMAX; j += i) {
				if (prime[j]) spf[j] = i;
				prime[j] = false;
			}
		}
	}
}

// get prime factorizations log(n)
unordered_map<ll, ll> getPrimeFactors(ll n) {
	unordered_map<ll, ll> mp;
	while (n != 1) {
		mp[spf[n]]++;
		n /= spf[n];
	}
	return mp;
}

// prime factors of numbers in nlogn time
const int PFCMAX = 1e7 + 8;
vector< unordered_map<ll, ll> > prime_factors_cnt(PFCMAX);
void precompute_prime_factors_cnt() {
	for (int i = 2; i < PFCMAX; i++) {
		unordered_map<ll, ll> mp = getPrimeFactors(i);
		prime_factors_cnt[i] = mp;
	}
}

// prime factors of numberes in nlogn time without using sieve
const int PFMAX = 1e6 + 1;
vi prime_factors[PFMAX];
void precompute_prime_factors() {
	for (int i = 2; i < PFMAX; i++) {
		if (prime_factors[i].size() == 0) {
			for (int j = i; j < PFMAX; j += i) {
				prime_factors[j].push_back(i);
			}
		}
	}
}

// factors for numbers
const int FMAX = 5e5 + 5;
vector< vi > factors(FMAX);
void precompute_factors() {
	for (int i = 1; i < FMAX; i++) {
		for (int j = i; j < FMAX; j += i) {
			factors[j].push_back(i);
		}
	}
}

// to get level of a number n in triangular number sequence
// logic: (x^2) + x = n, find x for level
ll triangle_level(ll n) {
	n = n * 2;
	ll b2_4ac = (4 * n) + 1;
	ll d = ceil(sqrt(b2_4ac)) - 1;
	ll level = round(d / 2.0);
	return level;
}

// next greater element in array O(n)
// function returns indexes(0-based) of next greater element in the array
vll nextGreaterElement(vll arr) {
	ll n = arr.size();
	vll res(n);
	if (n == 0) return res;

	stack<pll> s;
	s.push({arr[0], 0});
	for (ll i = 0; i < n; i++) {
		while (!s.empty() && s.top().first <= arr[i]) {
			res[s.top().second] = i;
			s.pop();
		}
		s.push({arr[i], i});
	}
	while (!s.empty()) {
		res[s.top().second] = -1;
		s.pop();
	}
	return res;
}

//calculates the modular multiplicative of a mod m.
//(assuming p is prime).
ll modInverse(ll a, ll p) {
	return bin_exp(a, p - 2, p);
}

// calculates C(n,k) mod p (assuming p is prime).
ll modBinomial(ll n, ll k, ll p) {
	ll numerator = 1;
	for (ll i = 0; i < k; i++) {
		numerator = (numerator * (n - i) ) % p;
	}
	ll denominator = 1;
	for (ll i = 1; i <= k; i++) {
		denominator = (denominator * i) % p;
	}
	return ( numerator * modInverse(denominator, p) ) % p;
}

// calculates factorial and inverse factorial mod p in O(n)
const int FIMAX = 3e5 + 8;
ll fact[FIMAX], invfact[FIMAX];
void fact_invfact() {
	fact[0] = 1;
	for (ll i = 1; i < FIMAX; i++) {
		fact[i] = fact[i - 1] * i;
		if (fact[i] >= MOD) {
			fact[i] = fact[i] % MOD;
		}
	}
	invfact[0] = 1;
	for (ll i = 1; i < FIMAX; i++) {
		invfact[i] = invfact[i - 1] * modInverse(i, MOD);
		if (invfact[i] >= MOD) {
			invfact[i] = invfact[i] % MOD;
		}
	}
}

// dijkstras algorithm for SSSP
void dijkstras(ll src, vll& dist, vector<vector<pll>>& adj, ll n) {
	vb vis(n + 1, false);
	dist[src] = 0;

	priority_queue<pll, vector<pll>, greater<pll>> nodes;
	nodes.push({0, src});
	while (!nodes.empty()) {
		ll u = nodes.top().second;
		nodes.pop();
		vis[u] = true;
		for (auto edge : adj[u]) {
			if (!vis[edge.second] and dist[u] + edge.first < dist[edge.second]) {
				dist[edge.second] = dist[u] + edge.first;
				nodes.push({dist[edge.second], edge.second});
			}
		}
	}
}

void setio() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

void solve() {

}

signed main() {
	clock_t p_start = clock();
	io;
	setio();

	tc{
		solve();
	}

	clock_t p_end = clock();
	cerr << "Time : " << fixed << setprecision(10) << (double)(p_end - p_start) / (double)CLOCKS_PER_SEC << " sec  ";
	return 0;
}
