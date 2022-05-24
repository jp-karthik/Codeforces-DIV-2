#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpll;
typedef vector<vector<int>> vvi;
typedef vector<vector<long long>> vvll;

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define rep(a, b) for(ll i=a; i<=b; i++)
#define Sort(v) sort(v.begin(), v.end())
#define revSort(v) sort(v.begin(), v.end(), greater<ll>())
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define PI 3.141592653589793238462
#define MOD 1000000007
#define INF 1e18


#ifndef ONLINE_JUDGE
	#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
	#define debug(x)
#endif 

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

void solve(int arg) {
 	string s;
 	cin >> s;
 	int n = s.length();
 	ll c0 = 0;
 	ll c1 = 0;
 	for (int i = 0; i < n; i++) {
 		if (s[i] == '0') {
 			c0++;
 		}
 	}
 	int l = 0;
 	int r = n-1;
 	while (1) {
 		if (l > r) {
 			cout << max(c0, c1) << endl;
 			return;
 		}
 		if (s[l] == '0') {
 			l++;
 			c0--;
 			continue;
 		}
 		if (s[r] == '0') {
 			r--;
 			c0--;
 			continue;
 		}
 		ll tl = l;
 		ll tr = r;
 		while (tl < r && s[tl] != '0') {
 			tl++;
 		}
 		if (tl == r) {
 			cout << max(c0, c1) << endl;
 			return;
 		}
 		while (tr > l && s[tr] != '0') {
 			tr--;
 		}

 		ll oneLeft = tl-l;
 		ll oneRight = r-tr;

 		ll zeroLeft = 0;
 		ll zeroRight = 0;

 		while (s[tl] == '0') {
 			zeroLeft++;
 			tl++;
 		}

 		while (s[tr] == '0') {
 			zeroRight++;
 			tr--;
 		}

		ll old = max(c1, c0);
		ll leftEffect = max(c1 + oneLeft, c0 - zeroLeft);
		ll rightEffect = max(c1 + oneRight, c0 - zeroRight);

		if (min(leftEffect, rightEffect) < old) {
			if (leftEffect < rightEffect) {
				c0 -= zeroLeft;
				c1 += oneLeft;
				l = tl;
			} else {
				c0 -= zeroRight;
				c1 += oneRight;
				r = tr;
			}
		} else {
			cout << max(c0, c1) << endl;
			return;
		}
 	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	int arg = 1;
	cin >> t;
	while(t > 0) {
	    solve(arg);
	    t--;
	    arg++;
	}
	return 0;
}