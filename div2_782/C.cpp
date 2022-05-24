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
void solve(int arg) {
    int n, a, b;
    cin>>n>>a>>b;

    vll v(n+1);
    vll pref(n+1, 0);

    REP(i, 1, n) cin>>v[i];

    REP(i, 1, n) pref[i] = pref[i-1]+v[i];

    //cap positions
    ll bestCost = LLONG_MAX;
    for (int i=0; i<=n; i++) {
        ll cost = b*(pref[n]-pref[i] -(n-i)*v[i]);
        cost += (a+b)*(v[i]);
        if (cost < bestCost) bestCost = cost;
    }
    cout<<bestCost<<endl;

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