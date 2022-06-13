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
#define input(x) for(auto& y : x) cin >> y
#define output(x) for (auto y : x) cout << y << endl 
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

vvi adjList;
vi nodes;
vi dp;

void calNode(int root , int parent) {
	nodes[root] = 1;
	for (auto child : adjList[root]) {
		if (child != parent) {
			calNode(child, root);
		}
	}
	for (auto child : adjList[root]) {
		if (child != parent) {
			nodes[root] += nodes[child];
		}
	}
}
void f(int root, int parent) {
	int deg = adjList[root].size();
	if (parent != -1) deg--;

	for (auto child : adjList[root]) {
		if (child != parent) {
			if (dp[child] == -1) {
				f(child, root);
			}
		}
	}

	if (deg == 2) {
		vi c;
		for (auto child : adjList[root]) {
			if (child != parent) {
				c.pb(child);
			}
		}
		dp[root] = max(dp[c[0]] + nodes[c[1]] - 1, dp[c[1]] + nodes[c[0]] - 1);
	} else if (deg == 1) {
		for (auto child : adjList[root]) {
			if (child != parent) {
				dp[root] = nodes[child] - 1;
				break;
			}
		}
	} else {
		dp[root] = 0;
	}
}

void solve(int arg) {
    int n;
    cin >> n;

    adjList.resize(n + 1);
    nodes.resize(n + 1, 0);
    dp.resize(n + 1, -1);

    for (int i = 0; i < n - 1; i++) {
    	int a, b;
    	cin >> a >> b;
    	adjList[a].pb(b);
    	adjList[b].pb(a);
    }

    calNode(1, -1);
    f(1, -1);
    cout << dp[1] << endl;

    adjList.clear();
    nodes.clear();
    dp.clear();
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