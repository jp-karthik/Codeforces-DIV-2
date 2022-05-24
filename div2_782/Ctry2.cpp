#include <bits/stdc++.h>
using namespace std;
// -------------------
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<long, long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<long long, long long>> vpll;
// --------------------
#define PB push_back
#define REP(i, a, b) for(int i=a; i<=b; i++)
#define sort(v) sort(v.begin(), v.end())
//------------------
bool dec(int x, int y) {
    return x>y;
}
bool inc(int x, int y) {
    return x<y;
}
//-----------------
ll n, a, b;
ll maxProfit(ll cap, ll curr, vll& x, ll* dp) {
    if (curr == n+1) {
        return dp[curr] = 0;
    }
    
    if  (dp[curr] != -1) return cap != 0 ? dp[curr]+abs(x[curr]-x[cap]): dp[curr]+abs(x[curr]);


    if (cap == 0) {
        ll x1 = maxProfit(cap, curr+1, x, dp) + b*abs(x[curr]);
        ll x2 = maxProfit(curr, curr+1, x, dp) + b*abs(x[curr]) + a*abs(x[curr]);
        return dp[curr] = min(x1, x2);
    }

    ll x1 = maxProfit(cap, curr+1, x, dp) + b*abs(x[curr]-x[cap]);
    ll x2 = maxProfit(curr, curr+1,x, dp) + b*abs(x[curr]-x[cap]) + a*abs(x[curr]-x[cap]);

    return dp[curr] = min(x1, x2);
}
void solve(int arg) {
    cin>>n>>a>>b;

    ll* dp = NULL;
    dp = new ll[n+2];
    for (int i=0; i<n+2; i++) {
        dp[i] = -1;
    }

    vll x(n+1);
    REP(i, 1, n) cin>>x[i];

    cout<<maxProfit(0, 1, x, dp)<<endl;

    delete [] dp;
    dp = NULL;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t > 0) {
        int arg = 0;
        solve(arg);
        t--;
        arg++;
    };
    return 0;
}