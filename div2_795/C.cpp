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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll res = 0;

    bool left = false;
    bool right = false;

    ll cnt = 0;
    ll l1 = -1;
    ll r1 = n;

    for (int i = 1; i < n-1; i++) {
    	if (s[i] == '1') {
    		l1 = i;
    		break;
    	}
    }
    for (int i = n-2; i >= 1; i--) {
    	if (s[i] == '1') {
    		r1 = i;
    		break;
    	}
    }
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '1') cnt++;
    }
    for (int i = 0; i < n-1; i++) {
    	string temp;
    	temp.pb(s[i]);
    	temp.pb(s[i+1]);
    	if (temp == "00") {
    		continue;
    	} else if (temp == "01") {
    		res += 1;
    	} else if (temp == "11") {
    		res += 11;
    	} else if (temp == "10") {
    		res += 10;
    	}
    }

    if (s[0] != '0') {
    	left = true;
    }
    if (s[n-1] != '0') {
    	right = true;
    }

    if (!left && !right) {
    	if (cnt >= 2 && abs(l1) + abs(n - 1 - r1) <= k) {
    		res -= 11;
    	} else if (cnt >= 1 && abs(n - 1 - r1) <= k) {
    		res -= 10;
    	} else if (cnt >= 1 && abs(l1) <= k) {
    		res -= 1;
    	}
    } else if (!right && left) {
    	if (cnt >= 1 && abs(n - 1 - r1) <= k) {
    		res -= 10;
    	}
    } else if (right && !left) {
    	if (cnt >= 1 && abs(l1) <= k) {
    		res -= 1;
    	}
    }
    if (cnt == 0 && !right && left && k >= n - 1) {
        res -= 9;
    }
    cout << res << endl;
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