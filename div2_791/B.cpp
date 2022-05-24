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
 	int n, q;
 	cin >> n >> q;
 	vll v(n);
 	for (int i = 0; i < n; i++) cin >> v[i];
 	ll sum = 0;
 	for (auto x : v) sum += x;
 	debug(sum);
 	//queries
 	ll eachVal = -1;
 	for (int i = 0; i < q; i++) {
 		int op;
 		cin >> op;
 		if (op == 1) {
 			if (eachVal == -1) {
 				ll idx, val;
	 			cin >> idx >> val;
	 			sum += val-v[idx-1];
	 			v[idx-1] = val;
	 			cout << sum << endl;
	 			continue;
 			}
 			vector<bool> b(n, false);
 			while (i < q && op == 1) {
 				ll idx, val;
 				cin >> idx >> val;
 				if (b[idx-1] == false) {
 					sum += val-eachVal;
 					v[idx-1] = val;
 					b[idx-1] = true;
 					cout << sum << endl;
 				} else {
 					sum += val-v[idx-1];
 					v[idx-1] = val;
 					cout << sum << endl;
 				}
 				i++;
 				cin >> op;
 			}
 			if (op == 2) {
 				ll val;
 				cin >> val;
 				sum = val*n;
 				eachVal = val;
 				cout << sum << endl;
 			}
 		
 		} else {
 			ll val;
 			cin >> val;
 			sum = val * n;
 			eachVal = val;
 			cout << sum << endl;
 		}
 	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arg;
	solve(arg);
	return 0;
}