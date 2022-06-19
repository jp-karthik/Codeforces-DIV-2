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

vvi board;
vector<vpll> dp;

void solve(int arg) {
    int n, m;
    cin >> n >> m;

    board.resize(n + 1, vi(m + 1));
    dp.resize(n + 1, vpll(m + 1, {0, 0}));
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		cin >> board[i][j];
    	}
    }

    if ((n + m) % 2 == 0) {
    	cout << "NO" << endl;
    	board.clear();
    	dp.clear();
    	return;
    }
    
    dp[1][1] = {board[1][1], board[1][1]};
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= m; j++) {
    		ll mini = LLONG_MAX;
    		ll maxi = LLONG_MIN;
    		if (i > 1) {
    			mini = min(mini, dp[i - 1][j].ff);
    			maxi = max(maxi, dp[i - 1][j].ss);
    		}
    		if (j > 1) {
    			mini = min(mini, dp[i][j - 1].ff);
    			maxi = max(maxi, dp[i][j - 1].ss);
    		}
    		dp[i][j].ff = mini == LLONG_MAX ? board[i][j] : mini + board[i][j];
    		dp[i][j].ss = maxi == LLONG_MIN ? board[i][j] : maxi + board[i][j];
    	}
    }
    if (dp[n][m].ff <= 0 && dp[n][m].ss >= 0) {
    	cout << "YES" << endl;
    } else {
    	cout << "NO" << endl;
    }
    board.clear();
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