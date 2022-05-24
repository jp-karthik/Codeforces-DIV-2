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

ll c1 = 0;
ll c0 = 0;
ll corner0 = 0;

bool isPossible(vll& suff, vll& pref, ll val) {
	for (int i = 0; i <= val; i++) {
		ll temp = pref[i] + suff[val-i] - corner0;
		if (c0-temp <= val) {
			return true;
		} 
	}
	return false;
}

void solve(int arg) {
 	string s;
 	cin >> s;
 
 	ll n = s.length();
 	for (int i = 0; i < n; i++) {
 		if (s[i] == '1') {
 			c1++;
 		} else {
 			c0++;
 		}
 	}

 	
 	for (int i = 0; i < n; i++) {
 		if (s[i] == '0') {
 			corner0++;
 			continue;
 		} else {
 			break;
 		}
 	}
 	for (int i = n-1; i >= 0; i--) {
 		if (s[i] == '0') {
 			corner0++;
 			continue;
 		} else {
 			break;
 		}
 	}

 	vll pref(c1+1);
 	vll suff(c1+1);

 	ll idx = 0;
 	ll i = 0;

 	pref[0] = corner0;
 	while (i < n && s[i] == '0') {
 		i++;
 	}
	for (; i < n;) {
 		if (i == n-1 && s[i] == '1') {
 			idx++;
 			i++;
 			pref[idx] = pref[idx-1];
 			continue;
 		}
 		if (i < n-1 && s[i] == '1' && s[i+1] == '1') {
 			idx++;
 			i++;
 			pref[idx] = pref[idx-1];
 			continue;
 		}
 		if (s[i] == '1') {
 			idx++;
 			i++;
 			if (idx == c1) {
 				pref[idx] = pref[idx-1];
 				break;
 			}
 			continue;
 		}
 		if (s[i] == '0') {
			ll local = 0;
			while (i < n && s[i] == '0') {
				local++;
				i++;
			}
			pref[idx] = pref[idx-1] + local;
 		} 
 	}

 	idx = 0;
 	suff[0] = corner0;
 	i = n-1;

 	while (i >= 0 && s[i] == '0') {
 		i--;
 	}
 	for (; i >= 0;) {
 		if (i == 0 && s[i] == '1') {
 			idx++;
 			i--;
 			suff[idx] = suff[idx-1];
 			continue;
 		}
 		if (i > 0 && s[i] == '1' && s[i-1] == '1') {
 			idx++;
 			i--;
 			suff[idx] = suff[idx-1];
 			continue;
 		}
 		if (s[i] == '1') {
 			idx++;
 			i--;
 			if (idx == c1) {
 				suff[idx] = suff[idx-1];
 				break;
 			}
 			continue;
 		}
 		if (s[i] == '0') {
			ll local = 0;
			while (i >= 0 && s[i] == '0') {
				local++;
				i--;
			}
			suff[idx] = suff[idx-1] + local;
 		} 
 	}
 	debug(pref);
 	debug(suff);

 	ll low = 0;
 	ll high = c1;
 	ll res = c1;

 	while (low <= high) {
 		ll mid = (low+high)/2;
 		if (isPossible(suff, pref, mid)) {
 			if (res > mid) {
 				debug(mid);
 				res = mid;
 			}
 			high = mid-1;
 		} else {
 			low = mid+1;
 		}
 	}
 	
 	debug(res);
	cout << res << endl;
	c1 = c0 = corner0 = 0;
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