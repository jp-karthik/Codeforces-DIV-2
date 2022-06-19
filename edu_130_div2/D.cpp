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

char query1(int i) {
	cout << "? 1 " << i + 1 << endl;
	cout.flush();

	char c;
	cin >> c;
	return c;
}

int query2(int l, int r) {
	cout << "? 2 " << l + 1 << " " << r + 1 << endl;
	cout.flush();

	int u;
	cin >> u;
	return u;
}

int count_unique(int l, int r, string s) {
	set<int> T;
	for (int i = l; i <= r; i++) {
		T.insert(s[i]);
	}
	return T.size();
}

void solve(int arg) {
    int n;
    cin >> n;

    string s(n, '?');

    map<char, int> last;
    for (char c = 'a'; c <= 'z'; c++) {
    	last[c] = -1;
    }

	int idx = 0;
    s[idx] = query1(idx);
	last[s[idx]] = idx;

    for (idx = 1; idx < n; idx++) {
    	if (query2(0, idx) == count_unique(0, idx - 1, s)) {
    		vector<pair<int, char>> v;
    		for (auto ele : last) {
    			if (ele.second != -1) {
    				v.pb({ele.second, ele.first});
    			}
    		}
   			Sort(v);
   			int low = 0;
   			int high = v.size() - 1;
   			int ans;
    		while (low <= high) {
    			int mid = (low + high) / 2;
    			if (query2(v[mid].first, idx) == count_unique(v[mid].first, idx - 1, s)) {
    				ans = mid;
					low = mid + 1;
    			} else {
					high = mid - 1;
    			}
    		}
			s[idx] = v[ans].second;
			last[s[idx]] = idx;
    	} else {
    		s[idx] = query1(idx);
			last[s[idx]] = idx;
    	}
    }
	cout << "! " << s << endl;
	cout.flush();
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("error.txt", "w", stderr);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t = 1;
	solve(t);
	return 0;
}