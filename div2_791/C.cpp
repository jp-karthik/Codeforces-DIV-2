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
 	vi X(n, 0);
 	vi Y(n, 0);
 	set<int> row, col;
 	for (int i = 0; i < n; i++) {
 		row.insert(i);
 		col.insert(i);
 	}
 	for (int i = 0; i < q; i++) {
 		int op;
 		cin >> op;
 		if (op == 1) {
 			int x, y;
 			cin >> x >> y;
 			if (!X[x-1]) {
 				row.erase(x-1);
 			}
 			if (!Y[y-1]) {
 				col.erase(y-1);
 			}
 			X[x-1]++;
 			Y[y-1]++;
 		} else if (op == 2) {
 			int x, y;
 			cin >> x >> y;
 			X[x-1]--, Y[y-1]--;
 			if (!X[x-1]) row.insert(x-1);
 			if (!Y[y-1]) col.insert(y-1);
 		} else {
 			int x1, y1, x2, y2;
 			cin >> x1 >> y1 >> x2 >> y2;
 			bool h = true;
 			bool v = true;
 			auto it1 = row.upper_bound(x1-2);
 			auto it2 = col.upper_bound(y1-2);
 			if (it1 == row.end() || it2 == col.end()) {
 				cout << "Yes" << endl;
 				continue;
 			}
 			if (*it1 >= x2 || *it2 >= y2) {
 				cout << "Yes" << endl;
 			} else {
 				cout << "No" << endl;
 			}
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