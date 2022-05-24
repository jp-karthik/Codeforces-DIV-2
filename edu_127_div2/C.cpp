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
    ll n, x;
    cin>>n>>x;

    vll v(n);
    vll pref(n);
    REP(i, 0, n-1) cin>>v[i];

    sort(v);
    ll days = 0;
    ll res = 0;

    pref[0] = v[0];
    for (int i=1; i<n; i++) {
        pref[i] = pref[i-1] + v[i];
    }

    ll ci =0;

    for (; ci<n; ci++) {
        if (pref[ci] > x) {
            break;
        }
    }
    ci--;

    while (ci >= 0) {
        while ( x < pref[ci] ) {
            ci--;
            if (ci < 0) {
                break;
            }
            pref[ci] += (ci+1)*(days);
        }
        ll td = (x-pref[ci])/(ci+1)+1;
        days += td;
        res += (ci+1)*(td);

        ci--;
        if (ci < 0) {
            break;
        }
        pref[ci] += (ci+1)*(days);
    }
    cout<<res<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int t;
    int arg = 1;
    cin>>t;
    while(t > 0) {
        solve(arg);
        t--;
        arg++;
    };
    return 0;
}