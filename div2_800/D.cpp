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

vi parent;
vvi adjList;
vll self;
vll help;
vpll lim;

int res = 0;
void dfs(int root, int parent) {
	for (auto node : adjList[root]) {
		dfs(node, root);
	}
	if (!adjList[root].size()) {
		self[root] = lim[root].ss;
		help[parent] += self[root];
		res++;
	} else {
		if (help[root] < lim[root].ff) {
			res++;
			self[root] = lim[root].ss;
			if (parent != -1) help[parent] += self[root];
		} else if (help[root] <= lim[root].ss) {
			self[root] = help[root];
			if (parent != -1) help[parent] += self[root];
		} else {
			self[root] = lim[root].ss;
			if (parent != -1) help[parent] += self[root];
		}
	}
}

void solve(int arg) {
    int n;
    cin >> n;
    parent.resize(n + 1);
    adjList.resize(n + 1);
    self.resize(n + 1);
    lim.resize(n + 1);
    help.resize(n + 1);
    for (int i = 2; i <= n; i++) {
    	int par;
    	cin >> par;
    	adjList[par].pb(i);
    	parent[i] = par;
    }
    for (int i = 1; i <= n; i++) {
    	cin >> lim[i].ff >> lim[i].ss;
    }
    dfs(1, -1);
    cout << res << endl;
    res = 0;
    parent.clear();
    adjList.clear();
    self.clear();
    lim.clear();
    help.clear();
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